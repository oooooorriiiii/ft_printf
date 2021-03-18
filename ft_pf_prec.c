/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:30:04 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 22:43:23 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
prec_checker(const char **fmt, va_list ap, int prec)
{
	(*fmt)++;
	if (**fmt == '*')
	{
		prec = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		prec = 0;
		while ('0' <= **fmt && **fmt <= '9')
		{
			prec *= 10;
			prec += **fmt - '0';
			(*fmt)++; 
		}
	}
	return (prec);
}

