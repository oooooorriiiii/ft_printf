/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:06:58 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 18:44:29 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
ptr_format(va_list ap, int flags, unsigned int format_num)
{
	unsigned long long	va_ptr_n;
	int					out_len;
	char				buf[64];
	char				*s;

	out_len = 0;
	flags |= ALTFLAG;
	va_ptr_n = (unsigned long long)va_arg(ap, void *);
	s = to_hex_string(buf, va_ptr_n, flags, sizeof(buf));
	out_len += out_putchar(s, flags, format_num);
	return (out_len);
}
