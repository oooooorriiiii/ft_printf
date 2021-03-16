/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:26:55 by ymori             #+#    #+#             */
/*   Updated: 2021/03/15 15:57:40 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
** normal text print.
** count the number of characters displayed..
*/

void
ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
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
prec_checker(char **fmt, int flags, unsigned int format_num)
{
	if (**fmt <= '0' && **fmt <= '9')
	{
		format_num *= 10;
		format_num += **fmt - '0';
		(*fmt)++;
	}
	return ;
}

static int
is_formatchar(char c)
{
	if (('0' <= c && c <= '9') || c == '#' || c == '+' || c == '-' || c == ' ')
		return (1);
	else
		return (0);
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
	while(**fmt != '\0' && !is_formatchar(**fmt))
	{
		/*flag: 0, -, #*/
		flag_checker(fmt, flags, format_num);
		/*width: *, .*/
		/*This is where it gets tricky.*/
		// width_checker(flags, format_num);
		/*prec*/
		prec_checker(fmt, flags, format_num);
		(*fmt)++;
	}
	/*formatting*/
		/*If argument is characters*/
		/*If argument is strings*/
		/*If argument is d, i, u, x, X, p*/
	/*printing*/
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

