/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:02:41 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 23:03:28 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
width_checker(const char **fmt, va_list ap, unsigned int format_num)
{
	if (**fmt == '*')
	{
		format_num = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		while ('0' <= **fmt && **fmt <= '9')
		{
			format_num *= 10;
			format_num += **fmt - '0';
			(*fmt)++;
		}
	}
	return (format_num);
}
