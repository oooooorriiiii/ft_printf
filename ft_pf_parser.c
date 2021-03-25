/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:30:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/25 17:49:28 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	is_flag_width_prec(const char c)
{
	if (('0' <= c && c <= '9') ||
		c == '#' || c == '+' || c == '-' || c == ' ' || c == '.' || c == '*')
		return (1);
	else
		return (0);
}

/*
** spc structure is complete within this function.
** width_checker returns spc structure, because it may add flags.
*/

int
	arg_print(const char **fmt, va_list *ap, int print_len)
{
	t_format	spc;

	spc.flags = 0;
	spc.width = 0;
	spc.prec = -1;
	if (percent_printed(fmt))
		return (++print_len);
	while (**fmt != '\0' && is_flag_width_prec(**fmt))
	{
		spc.flags = flag_checker(fmt, spc.flags, spc.width);
		spc = width_checker(fmt, ap, spc);
		if (**fmt == '.')
			spc.prec = prec_checker(fmt, ap, spc.prec);
	}
	print_len = formatting(fmt, ap, &spc, print_len);
	(*fmt)++;
	return (print_len);
}
