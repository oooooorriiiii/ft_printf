/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:26:55 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 20:51:52 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

#include <stdio.h>

static int
args_print(const char **fmt, va_list ap, int print_len)
{
	int				flags;
	unsigned int	format_num;

	flags = 0;
	format_num = 0;
	/*is %*/
	if (percent_printed(fmt))
		return (++print_len);
	/*parse*/
	while(**fmt != '\0' && is_flag_width_prec(**fmt))
	{
		/*flag: 0, -, #*/
		flags = flag_checker(fmt, flags, format_num);
		/*prec*/
		format_num = width_checker(fmt, format_num);
		/*width: *, .*/
		/*This is where it gets tricky.*/
		// width_checker(flags, format_num);
		// width_checker(flags, format_num);
	}
	/*formatting and printing*/
	print_len = formatting(fmt, ap, flags, format_num, print_len); 
	(*fmt)++;
	return (print_len);
}

/* 
** Operate fmt from this function
*/
static int
ft_dprintf(const char *fmt, va_list ap)
{
	int			print_len;

	print_len = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_len = plain_text_print(&fmt, print_len);
		else
		{
			fmt++;
			print_len = args_print(&fmt, ap, print_len);
		}
	}
	return (print_len);
}

int
ft_printf(const char *fmt, ...)
{
	int			print_len;
	va_list		ap;

	print_len = 0;
	va_start(ap, fmt);
	print_len = ft_dprintf(fmt, ap);
	va_end(ap);
	return (print_len);
}

