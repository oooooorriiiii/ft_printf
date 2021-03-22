/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:51:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/22 16:00:38 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
plain_text_print(const char **c, int print_len)
{
	ft_putchar((const char)(**c));
	(*c)++;
	return (++print_len);
}

int
percent_printed(const char **fmt)
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

int
out_putchar(const char *s, int flags, int width, int prec)
{
	int		count;
	int		str_len;
	int		out_len;
	char	pad_char;

	count = 0;
	out_len = 0;
	str_len = ft_strlen(s);
	/* flag is '0' */
	pad_char= (flags & LEADZEROFLAG) ? '0' : ' ';
	/* flag is '-' */
	/* TODO: All this implememtation may need to be changed. */
	/*
	** if (prec >= width)
	**  width = prec;
	** if (prec > 0 && str_len >= prec)
	**  prec = strlen;
	** if (str_len >= width)
	**  width = strlen;
	**
	*/
	if (flags & LEFTFORMATFLAG)
	{
		/* prec */
		while (*s != 0)
		{
			ft_putchar(*s++);
			out_len++;
			count++;
		}
		while (width > count)
		{
			ft_putchar(' ');
			out_len++;
			width--;
		}
	}
	else
	{
		while (width > str_len)
		{
			/* prec */
			while (prec > str_len)
			{
				ft_putchar('0');
				out_len++;
				width--;
				prec--;
			}
			if (width == str_len)
				break ;
			ft_putchar(pad_char);
			out_len++;
			width--;
		}
		while (*s != 0)
		{
			ft_putchar(*s++);
			out_len++;
		}
	}
	return (out_len);
}		

