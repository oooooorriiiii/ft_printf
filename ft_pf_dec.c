/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:55:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/30 15:08:16 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	add_minus_sign(char *buf, t_format spc,
					int count, int i)
{
	int		count_for_width;
	int		count_for_prec;

	count_for_width = count;
	count_for_prec = count;
	if ((spc.flags & LEADZEROFLAG) && spc.prec < 0
			&& !(spc.flags & LEFTFORMATFLAG))
	{
		while (spc.width-- > count_for_width + 1)
		{
			buf[--i] = '0';
			count_for_prec++;
		}
	}
	while (spc.prec-- > count_for_prec)
		buf[--i] = '0';
	buf[--i] = '-';
	return (i);
}

static char
	*to_dec_string(char *buf, unsigned long long n, t_format spc, int str_len)
{
	int		i;
	int		neg;
	int		count;

	neg = ((spc.flags & SIGNEDFLAG) && (long long)n < 0) ? 1 : 0;
	count = 1;
	i = str_len;
	if ((spc.flags & SIGNEDFLAG) && (long long)n < 0)
		n = -n;
	buf[--i] = '\0';
	buf[--i] = (n % 10) + '0';
	n /= 10;
	while (n != 0)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
		count++;
	}
	if (neg)
		i = add_minus_sign(buf, spc, count, i);
	else if (spc.flags & SHOWSIGNFLAG)
		buf[--i] = '+';
	else if (spc.flags & SPACEFLAG)
		buf[--i] = ' ';
	return (&buf[i]);
}

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
	dec_format(const char **fmt, va_list *ap, t_format *spc)
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
		spc->flags |= SIGNEDFLAG;
	}
	else if (**fmt == 'u')
		va_n = va_arg(*ap, unsigned int);
	if (va_n == 0 && spc->prec == 0)
		out_len += put_width_space(spc->width, out_len);
	else
	{
		s = to_dec_string(buf, va_n, *spc, sizeof(buf));
		out_len += out_nbr(s, spc);
	}
	return (out_len);
}
