/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:30:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 01:48:07 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int 
flag_checker(const char **fmt, int flags, unsigned int format_num)
{
	if (**fmt == '0' && format_num == 0)
		flags |= LEADZEROFLAG;
	else if (**fmt == '-')
		flags |= LEFTFORMATFLAG;
	else if (**fmt == '+')
		flags |= SHOWSIGNFLAG;
	else if (**fmt == '#')
		flags |= ALTFLAG;
	else
		return flags;	
	(*fmt)++;
	return flags;
}

int
prec_checker(const char **fmt, int flags, unsigned int format_num)
{
	while ('0' <= **fmt && **fmt <= '9')
	{
		format_num *= 10;
		format_num += **fmt - '0';
		(*fmt)++;
	}
	return (format_num);
}

int
is_flag_width_prec(const char c)
{
	if (('0' <= c && c <= '9') || c == '#' || c == '+' || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}
