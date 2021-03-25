/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:02:41 by ymori             #+#    #+#             */
/*   Updated: 2021/03/24 02:44:37 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

t_format
	width_checker(const char **fmt, va_list *ap, t_format spc)
{
	if (**fmt == '*')
	{
		spc.width = va_arg(*ap, int);
		(*fmt)++;
	}
	else
	{
		while ('0' <= **fmt && **fmt <= '9')
		{
			spc.width *= 10;
			spc.width += **fmt - '0';
			(*fmt)++;
		}
	}
	if (spc.width < 0)
	{
		spc.flags |= LEFTFORMATFLAG;
		spc.width = -spc.width;
	}
	return (spc);
}

