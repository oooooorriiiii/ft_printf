/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:02:41 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 18:36:34 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
width_checker(const char **fmt, va_list *ap, int *flags, int width)
{
	if (**fmt == '*')
	{
		width = va_arg(*ap, int);
		(*fmt)++;
	}
	else
	{
		while ('0' <= **fmt && **fmt <= '9')
		{
			 width *= 10;
			 width += **fmt - '0';
			(*fmt)++;
		}
	}
	if (width < 0)
	{
		*flags |= LEFTFORMATFLAG;
		width = -width;
	}
	return (width);
}

