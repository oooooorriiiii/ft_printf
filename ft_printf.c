/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:26:55 by ymori             #+#    #+#             */
/*   Updated: 2021/03/17 01:01:31 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
** normal text print.
** count the number of characters displayed..
**
*/

void
ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

int
ft_strlen(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}


static int
plain_text_print(char **c, int print_len)
{
	ft_putchar(**c);
	(*c)++;
	return (++print_len);
}

static int
percent_printed(char **fmt)
{
	if (**fmt == '%')
	{
		ft_putchar('%');
		(*fmt)++;
		return (1);
	}
	else
		return (0);
}

static void
flag_checker(char **fmt, int flags, unsigned int format_num)
{
	if (**fmt == '0' && format_num == 0)
		flags |= LEADZEROFLAG;
	else if (**fmt == '-')
		flags |= LEFTFORMATFLAG;
	else if (**fmt == '+')
		flags |= SHOWSIGNFLAG;
	else if (**fmt == '#')
		flags |= ALTFLAG;
	(*fmt)++;
	return ;
}

static void
prec_checker(char **fmt, int flags, unsigned int *format_num)
{
	if (**fmt <= '0' && **fmt <= '9')
	{
		*format_num *= 10;
		*format_num += **fmt - '0';
		(*fmt)++;
	}
	return ;
}

static int
is_flag_width_prec(char c)
{
	if (('0' <= c && c <= '9') || c == '#' || c == '+' || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}

static int
character_format(char **fmt, va_list ap, int flags, int print_len)
{
	unsigned char	uc;

	uc = va_arg(ap, unsigned int);
	ft_putchar(uc);
	return (++print_len);
}

/*using format_num*/
static void
out_putchar(char *s, int flags, int format_num)
{
	unsigned int	count;
	size_t			str_len;
	char			outchar;

	count = 0;
	str_len = ft_strlen(s);
	outchar = (flags & LEADZEROFLAG) ? '0' : ' ';
	if (flags & LEFTFORMATFLAG)
	{
		while (*s != 0)
		{
			ft_putchar(*s++);
			count++;
		}
		while (format_num > count)
		{
			ft_putchar(' ');
			format_num--;
		}
	}
	else
	{
		while (format_num > str_len)
		{
			ft_putchar(outchar);
			format_num--;
		}
		while (*s != 0)
			ft_putchar(*s++);
	}	
}		

static int
string_format(char **fmt, va_list ap, int flags, unsigned int format_num, int print_len)
{
	const char	*s;

	s = va_arg(ap, const char *);
	if (s == 0)
	{
		s = "(null)";
		out_putchar(s, flags, format_num);
		return (0);
	}
	else
	{
		out_putchar(s, flags, format_num);
		return (ft_strlen(s));
	}
}

/*TODO: It is necessary to allocate a string for display somewhere.*/
/*using "format_num"*/
static int 
formatting(char **fmt, va_list ap, int flags, unsigned int format_num, int print_len)
{
	if (**fmt == 'c')
	/*If argument is characters*/
		print_len = character_format(fmt, ap, flags, print_len);
	else if (**fmt == 's')
	/*If argument is strings*/
		print_len = string_format(fmt, ap, flags, format_num, print_len);
	/*If argument is d, i, u, x, X, p*/
	return (print_len);
}

static int
args_print(char **fmt, va_list ap, int print_len)
{
	int				flags;
	unsigned int	format_num;

	flags = 0;
	format_num = 0;
	/*is %*/
	if (percent_printed(fmt))
		return (++print_len);
	/*parse*/
	while(**fmt != '\0' && is_flag_width_prec(**fmt))
	{
		/*flag: 0, -, #*/
		flag_checker(fmt, flags, format_num);
		/*width: *, .*/
		/*This is where it gets tricky.*/
		// width_checker(flags, format_num);
		/*prec*/
		prec_checker(fmt, flags, &format_num);
		(*fmt)++;
	}
	/*formatting*/
	print_len = formatting(fmt, ap, flags, format_num, print_len); 
	(*fmt)++;
	return (print_len);
}

/* Operate fmt from this function */
static int
ft_dprintf(char *fmt, va_list ap)
{
	int			print_len;

	print_len = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_len = plain_text_print(&fmt, print_len);
		else
		{
			fmt++;
			print_len = args_print(&fmt, ap, print_len);
		}
	}
	return (print_len);
}

int
ft_printf(const char *fmt, ...)
{
	int			print_len;
	va_list		ap;

	print_len = 0;
	va_start(ap, fmt);
	print_len = ft_dprintf(fmt, ap);
	va_end(ap);
	return (print_len);
}

