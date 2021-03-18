/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:27:29 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 15:46:33 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> // AAAAAAAAAAAAA

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c);
int		ft_strlen(const char *s);

#endif
