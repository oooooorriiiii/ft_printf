/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_out_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:51:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/27 02:49:08 by ymori            ###   ########.fr       */
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
	out_char(const char c, t_format *spc)
{
	int		out_len;
	int		count;
	int		width;

	out_len = 0;
	count = 0;
	width = spc->width;
	while (width-- > 1 && !(spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		out_len++;
		count++;
	}
	ft_putchar(c);
	count++;
	out_len++;
	while (count < spc->width && (spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		out_len++;
		count++;
	}
	return (out_len);
}

int
	out_str(const char *s, t_format *spc)
{
	int		out_len;
	int		fmt_len;
	int		count;
	int		width;
	int		prec;

	out_len = 0;
	count = 0;
	width = spc->width;
	prec = spc->prec;
	fmt_len = (prec > 0 && ft_strlen(s) >= prec) ? prec : ft_strlen(s);
	if (prec == 0)
	{
		while (width-- > 0)
		{
			ft_putchar(' ');
			out_len++;
		}
		return (out_len);
	}
	while (width-- > fmt_len && !(spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		count++;
		out_len++;
	}
	if (prec < 0)
	{
		while (*s != 0)
		{
			ft_putchar(*s);
			out_len++;
			count++;
			s++;
		}
	}
	else
	{
		while (*s != 0 && prec-- > 0)
		{
			ft_putchar(*s);
			out_len++;
			count++;
			s++;
		}
	}
	while (count < spc->width && (spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		out_len++;
		count++;
	}
	return (out_len);
}
