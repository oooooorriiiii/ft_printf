/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:55:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 18:45:30 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static char
*to_dec_string(char *buf, unsigned long long n, int flag, int width, int prec, int str_len)
{
	int		i;
	int		neg;
	int		count_for_width;
	int		count_for_prec;

	neg = 0;
	count_for_width = 1;
	count_for_prec = 1;
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
		count_for_width++;
		count_for_prec++;
	}
	if (neg)
	{
		if ((flag & LEADZEROFLAG) && prec < 0 && !(flag & LEFTFORMATFLAG))
		{
			while (width-- > count_for_width + 1)
			{
				buf[--i] = '0';
				count_for_prec++;
			}
		}
		while (prec-- > count_for_prec)
			buf[--i] = '0';
		buf[--i] = '-';
	}
	else if (flag & SHOWSIGNFLAG)
		buf[--i] = '+';
	return (&buf[i]);
}

int
dec_format(const char **fmt, va_list *ap, int flags, int width, int prec)
{
	unsigned long long	va_n;
	int					out_len;
	char				buf[64];
	char				*s;

	va_n = 0;
	out_len = 0;
	if (**fmt == 'd' || **fmt == 'i')
	{
		va_n = va_arg(*ap, int);
		flags |= SIGNEDFLAG;
	}
	else if (**fmt == 'u')
		va_n = va_arg(*ap, unsigned int);
	/* 
	** It does not consider shat happens when the precision and
	** width are specified at the same time.
	*/
	if (!(va_n == 0 && prec == 0))
	{
		s = to_dec_string(buf, va_n, flags, width, prec, sizeof(buf));
		out_len += out_putchar(s, flags, width, prec);
	}
	else
	{
		while (width-- > 0)	
		{
			ft_putchar(' ');
			out_len++;
		}
	}
	return (out_len);
}

