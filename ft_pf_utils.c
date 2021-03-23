/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:28:22 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 20:53:19 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_pf_utils.h"

void
	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

int
	ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}
