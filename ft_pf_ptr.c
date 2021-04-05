/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:06:58 by ymori             #+#    #+#             */
/*   Updated: 2021/04/05 20:25:28 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	put_width_space(int width, int out_len)
{
	while (width-- > 0)
	{
		ft_putchar(' ');
		out_len++;
	}
	return (out_len);
}

int
	ptr_format(va_list *ap, t_format *spc)
{
	unsigned long long	va_ptr_n;
	int					out_len;
	char				buf[64];
	char				*s;

	out_len = 0;
	spc->flags |= ALTFLAG;
	spc->flags |= PTRFLAG;
	va_ptr_n = (unsigned long long)va_arg(*ap, void *);
	if (va_ptr_n == 0 && spc->prec == 0)
	{
		out_len += put_width_space(spc->width - 2, out_len);
		ft_putchar('0');
		ft_putchar((spc->flags & ALTFLAG) ? 'X' : 'x');
		out_len += 2;
	}
	else
	{
		s = to_hex_string(buf, va_ptr_n, spc, sizeof(buf));
		out_len += out_nbr(s, spc);
	}
	return (out_len);
}
