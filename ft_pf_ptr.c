/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:06:58 by ymori             #+#    #+#             */
/*   Updated: 2021/03/30 22:44:28 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
	ptr_format(va_list *ap, t_format *spc)
{
	unsigned long long	va_ptr_n;
	int					out_len;
	char				buf[64];
	char				*s;

	out_len = 0;
	spc->flags |= ALTFLAG;
	va_ptr_n = (unsigned long long)va_arg(*ap, void *);
	if (spc->prec == 0)
	{
		spc->width--;
		out_len = out_char('0', spc);
		ft_putchar((spc->flags & CAPSFLAG) ? 'X' : 'x');
		out_len++;
	}
	else
	{
		s = to_hex_string(buf, va_ptr_n, spc, sizeof(buf));
		out_len += out_nbr(s, spc);
	}
	return (out_len);
}
