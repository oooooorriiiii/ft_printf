/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:53:03 by ymori             #+#    #+#             */
/*   Updated: 2021/03/20 16:26:01 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static void
digits_init(char *digits)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		digits[i] = "0123456789abcdef"[i];
		i++;
	}
	digits[i] = '\0';
}

static void
digits_caps_init(char *digits)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		digits[i] = "0123456789ABCDEF"[i];
		i++;
	}
	digits[i] = '\0';
}

char
*to_hex_string(char *buf, unsigned long long n, int flag, int str_len)
{
	int		i;
	char	digits[17];
	char	digits_caps[17]; 
	char	*table;

	i = str_len;
	digits_init(digits);
	digits_caps_init(digits_caps);
	if (flag & CAPSFLAG)
		table = digits_caps;
	else
		table = digits;	
	buf[--i] = '\0';
	buf[--i] = table[n % 16];
	n /= 16;
	while (n != 0)
	{
		buf[--i] = table[n % 16];
		n /= 16;
	}
	if (flag & ALTFLAG)
	{
		buf[--i] = (flag & CAPSFLAG) ? 'X' : 'x';
		buf[--i] = '0';
	}
	return (&buf[i]);	
}

int
hex_format(const char **fmt, va_list *ap, int flags, int width, int prec)
{
	unsigned long long	va_n;
	int					out_len;
	char				buf[64];
	char				*s;

	out_len = 0;
	if (**fmt == 'X')
		flags |= CAPSFLAG;
	va_n = va_arg(*ap, unsigned int);
	s = to_hex_string(buf, va_n, flags, sizeof(buf));
	out_len += out_putchar(s, flags, width, prec);
	return (out_len);
}


