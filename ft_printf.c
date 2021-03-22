/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:26:55 by ymori             #+#    #+#             */
/*   Updated: 2021/03/20 15:41:03 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

static int
args_print(const char **fmt, va_list *ap, int print_len)
{
	int		flags;
	int		width;
	int		prec;

	flags = 0;
	width = 0;
	prec = -1;
	if (percent_printed(fmt))
		return (++print_len);
	while(**fmt != '\0' && is_flag_width_prec(**fmt))
	{
		flags = flag_checker(fmt, flags, width);
		width = width_checker(fmt, ap, width);
		if (**fmt == '.')
			prec = prec_checker(fmt, ap, prec);
	}
	print_len = formatting(fmt, ap, flags, width, prec, print_len);
	(*fmt)++;
	return (print_len);
}

static int
ft_dprintf(const char *fmt, va_list *ap)
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
	print_len = ft_dprintf(fmt, &ap);
	va_end(ap);
	return (print_len);
}

