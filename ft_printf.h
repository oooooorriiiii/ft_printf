/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:27:29 by ymori             #+#    #+#             */
/*   Updated: 2021/03/16 22:37:09 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define CAPSFLAG		0x00000001
# define SIGNEDFLAG		0x00000002
# define LEFTFORMATFLAG	0x00000004
# define LEADZEROFLAG	0x00000008
# define SHOWSIGNFLAG	0x00000010
# define ALTFLAG		0x000000220

int		ft_printf(const char *fmt, ...);
int		ft_strlen(char *s);

#endif
