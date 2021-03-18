/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:51:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 18:46:15 by ymori            ###   ########.fr       */
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
percent_printed(const char **fmt)
{
	if (**fmt == '%')
	{
		ft_putchar('%');
		(*fmt)++;
		return (1);
	}
	else
		return (0);
}

/*using format_num*/
int
out_putchar(const char *s, int flags, int format_num)
{
	int		count;
	int		str_len;
	int		out_len;
	char	outchar;

	count = 0;
	out_len = 0;
	str_len = ft_strlen(s);
	outchar = (flags & LEADZEROFLAG) ? '0' : ' ';
	if (flags & LEFTFORMATFLAG)
	{
		while (*s != 0)
		{
			ft_putchar(*s++);
			out_len++;
			count++;
		}
		while (format_num > count)
		{
			ft_putchar(' ');
			out_len++;
			format_num--;
		}
	}
	else
	{
		while (format_num > str_len)
		{
			ft_putchar(outchar);
			out_len++;
			format_num--;
		}
		while (*s != 0)
		{
			ft_putchar(*s++);
			out_len++;
		}
	}	
	return (out_len);
}		

