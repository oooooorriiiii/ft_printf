/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:44:45 by ymori             #+#    #+#             */
/*   Updated: 2021/03/30 14:22:04 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	is_numargument(const char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	else
		return (0);
}

int
	character_format(va_list *ap, t_format *spc)
{
	unsigned char	uc;
	int				out_len;

	out_len = 0;
	uc = va_arg(*ap, unsigned int);
	out_len = out_char(uc, spc);
	return (out_len);
}

int
	string_format(va_list *ap, t_format *spc)
{
	const char		*s;
	int				out_len;

	s = va_arg(*ap, const char *);
	out_len = 0;
	if (s == 0)
	{
		s = "(null)";
		out_len = out_str(s, spc);
		return (out_len);
	}
	else
	{
		out_len = out_str(s, spc);
		return (out_len);
	}
}

int
	num_format(const char **fmt, va_list *ap, t_format *spc)
{
	int		out_len;

	out_len = 0;
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u')
		out_len = dec_format(fmt, ap, spc);
	else if (**fmt == 'x' || **fmt == 'X')
		out_len = hex_format(fmt, ap, spc);
	else if (**fmt == 'p')
		out_len = ptr_format(ap, spc);
	return (out_len);
}

int
	formatting(const char **fmt, va_list *ap, t_format *spc, int print_len)
{
	if (**fmt == '%')
		print_len += percent_printed(spc);
	else if (**fmt == 'c')
		print_len += character_format(ap, spc);
	else if (**fmt == 's')
		print_len += string_format(ap, spc);
	else if (is_numargument(**fmt))
		print_len += num_format(fmt, ap, spc);
	return (print_len);
}
