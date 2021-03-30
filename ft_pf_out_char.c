/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_out_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:51:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/30 14:35:11 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

int
	plain_text_print(const char **c, int print_len)
{
	ft_putchar((const char)(**c));
	(*c)++;
	return (++print_len);
}

int
	percent_printed(t_format *spc)
{
	int		out_len;

	out_len = 0;
	out_len = out_nbr("%", spc);
	return (out_len);
}

int
	out_char(const char c, t_format *spc)
{
	int		out_len;
	int		count;
	int		width;

	out_len = 0;
	count = 0;
	width = spc->width;
	while (width-- > 1 && !(spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		out_len++;
		count++;
	}
	ft_putchar(c);
	count++;
	out_len++;
	while (count < spc->width && (spc->flags & LEFTFORMATFLAG))
	{
		ft_putchar(' ');
		out_len++;
		count++;
	}
	return (out_len);
}
