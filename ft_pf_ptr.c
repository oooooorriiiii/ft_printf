/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:06:58 by ymori             #+#    #+#             */
/*   Updated: 2021/03/25 17:50:35 by ymori            ###   ########.fr       */
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
	s = to_hex_string(buf, va_ptr_n, spc->flags, sizeof(buf));
	out_len += out_putchar(s, spc);
	return (out_len);
}
