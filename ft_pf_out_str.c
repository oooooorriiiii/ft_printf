/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_out_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:07:24 by ymori             #+#    #+#             */
/*   Updated: 2021/03/27 15:49:51 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	prec_zero(int width, int out_len)
{
	while (width-- > 0)
	{
		ft_putchar(' ');
		out_len++;
	}
	return (out_len);
}

static int
	str_print(const char *s, int prec, int *count)
{
	int		out_len;

	out_len = 0;
	if (prec < 0)
	{
		while (*s != 0)
		{
			ft_putchar(*s);
			out_len++;
			(*count)++;
			s++;
		}
	}
	else
	{
		while (*s != 0 && prec-- > 0)
		{
			ft_putchar(*s);
			out_len++;
			(*count)++;
			s++;
		}
	}
	return (out_len);
}

static int
	out_space(int *count)
{
	ft_putchar(' ');
	(*count)++;
	return (1);
}

int
	out_str(const char *s, t_format *spc)
{
	int		out_len;
	int		fmt_len;
	int		count;
	int		width;

	out_len = 0;
	count = 0;
	width = spc->width;
	fmt_len = (spc->prec > 0 && ft_strlen(s) >= spc->prec) ?
				spc->prec : ft_strlen(s);
	if (spc->prec == 0)
		return (prec_zero(width, out_len));
	while (width-- > fmt_len && !(spc->flags & LEFTFORMATFLAG))
		out_len += out_space(&count);
	out_len += str_print(s, spc->prec, &count);
	while (count < spc->width && (spc->flags & LEFTFORMATFLAG))
		out_len += out_space(&count);
	return (out_len);
}
