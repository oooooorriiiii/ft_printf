/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_out_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:20:34 by ymori             #+#    #+#             */
/*   Updated: 2021/03/27 02:49:20 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	out_nbr_leftformat(const char *s, t_format *spc, int str_len)
{
	int		out_len;
	int		count;

	out_len = 0;
	count = 0;
	while (spc->prec-- > str_len)
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
	while (spc->width > count)
	{
		ft_putchar(' ');
		out_len++;
		spc->width--;
	}
	return (out_len);
}

static int
	out_nbr_normal(const char *s, t_format *spc, int str_len, char pad_char)
{
	int		out_len;

	out_len = 0;
	while (spc->width > spc->prec && spc->width > str_len)
	{
		ft_putchar(pad_char);
		out_len++;
		spc->width--;
	}
	while (spc->prec-- > str_len)
	{
		ft_putchar('0');
		out_len++;
	}
	while (*s != 0)
	{
		ft_putchar(*s++);
		out_len++;
	}
	return (out_len);
}

int
	out_nbr(const char *s, t_format *spc)
{
	int		str_len;
	int		out_len;
	char	pad_char;

	out_len = 0;
	str_len = ft_strlen(s);
	pad_char = (spc->prec < 0 && (spc->flags & LEADZEROFLAG)) ? '0' : ' ';
	if ((spc->flags & LEFTFORMATFLAG))
		out_len = out_nbr_leftformat(s, spc, str_len);
	else
		out_len = out_nbr_normal(s, spc, str_len, pad_char);
	return (out_len);
}
