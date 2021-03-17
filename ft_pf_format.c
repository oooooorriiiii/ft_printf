/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:44:45 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 02:40:55 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
character_format(const char **fmt, va_list ap, int flags)
{
	unsigned char	uc;

	uc = va_arg(ap, unsigned int);
	ft_putchar(uc);
	return (1);
}


int
string_format(const char **fmt, va_list ap, int flags, unsigned int format_num)
{
	const char		*s;
	unsigned int	out_len;

	s = va_arg(ap, const char *);
	out_len = 0;
	if (s == 0)
	{
		s = "(null)";
		out_putchar(s, flags, format_num);
		return (out_len);
	}
	else
	{
		out_len = out_putchar(s, flags, format_num);
		return (out_len); // It does not work the way it is written.
	}
}

/*TODO: It is necessary to allocate a string for display somewhere.*/
/*using "format_num"*/
int 
formatting(const char **fmt, va_list ap, int flags, unsigned int format_num, int print_len)
{
	if (**fmt == 'c')
	/*If argument is characters*/
		print_len += character_format(fmt, ap, flags);
	else if (**fmt == 's')
	/*If argument is strings*/
		print_len += string_format(fmt, ap, flags, format_num);
	/*If argument is d, i, u, x, X, p*/
	return (print_len);
}

