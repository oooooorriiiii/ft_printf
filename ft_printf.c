/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:26:55 by ymori             #+#    #+#             */
/*   Updated: 2021/03/25 17:51:49 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
	ft_dprintf(const char *fmt, va_list *ap)
{
	int		print_len;

	print_len = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_len = plain_text_print(&fmt, print_len);
		else
		{
			fmt++;
			print_len = arg_print(&fmt, ap, print_len);
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
	print_len = ft_dprintf(fmt, &ap);
	va_end(ap);
	return (print_len);
}
