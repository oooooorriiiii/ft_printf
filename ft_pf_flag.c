/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:03:57 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 21:12:08 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
	flag_checker(const char **fmt, int flags, int format_num)
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
		return (flags);
	(*fmt)++;
	return (flags);
}
