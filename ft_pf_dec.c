/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:55:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 15:38:02 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static char
*to_dec_string(char *buf, unsigned long long n, int flag, int str_len)
{
	int		i;
	int		neg;

	neg = 0;
	i = str_len;
	if ((flag & SIGNEDFLAG) && (long long)n < 0)
	{
		neg = 1;
		n = -n;
	}
	buf[--i] = '\0';
	buf[--i] = (n % 10) + '0';
	n /= 10;
	while (n != 0)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		buf[--i] = '-';
	else if (flag & SHOWSIGNFLAG)
		buf[--i] = '+';
	return (&buf[i]);
}

int
dec_format(const char **fmt, va_list ap, int flags, unsigned int format_num)
{
	int		va_n;
	int		out_len;
	char	buf[64];
	char	*s;

	out_len = 0;
	va_n = va_arg(ap, int);
	flags |= SIGNEDFLAG;
	s = to_dec_string(buf, va_n, flags, sizeof(buf));

	out_len = out_putchar(s, flags, format_num);
	return (out_len);
}
	
