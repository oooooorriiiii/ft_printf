/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:51:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 21:18:46 by ymori            ###   ########.fr       */
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
	pad_char = (prec < 0 && (flags & LEADZEROFLAG)) ? '0' : ' ';
	if (prec >= width)
		width = prec;
	if (prec > 0 && str_len >= prec)
		prec = str_len;
	if (str_len >= width)
		width = str_len;
	if ((flags & LEFTFORMATFLAG))
	{
		while (prec-- > str_len)
		{
			ft_putchar('0');
			count++;
			out_len++;
		}
		while (*s != 0)
		{
			ft_putchar(*s++);
			count++;
			out_len++;
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
		while (width > prec && width > str_len)
		{
			ft_putchar(pad_char);
			out_len++;
			width--;
		}
		while (prec-- > str_len)
		{
			ft_putchar('0');
			out_len++;
		}
		while (*s != 0)
		{
			ft_putchar(*s++);
			out_len++;
		}
	}
	return (out_len);
}
