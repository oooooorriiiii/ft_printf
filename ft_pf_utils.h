/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:53:06 by ymori             #+#    #+#             */
/*   Updated: 2021/03/18 02:38:35 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PF_UTILS_H 
# define FT_PF_UTILS_H 

# define CAPSFLAG		0x00000001
# define SIGNEDFLAG		0x00000002
# define LEFTFORMATFLAG	0x00000004
# define LEADZEROFLAG	0x00000008
# define SHOWSIGNFLAG	0x00000010
# define ALTFLAG		0x000000220

/* ft_printf.c */


/* ft_pf_format.c */
int character_format(const char **fmt, va_list ap, int flags);
int string_format(const char **fmt, va_list ap, int flags, unsigned int format_num);
int formatting(const char **fmt, va_list ap, int flags, unsigned int format_num, int print_len);

/* ft_pf_parser.c*/
int flag_checker(const char **fmt, int flags, unsigned int format_num);
int prec_checker(const char **fmt, int flags, unsigned int format_num);
int is_flag_width_prec(const char c);

/* ft_output.c */
int plain_text_print(const char **c, int print_len);
int percent_printed(const char **fmt);
int out_putchar(const char *s, int flags, int format_num);

#endif 
