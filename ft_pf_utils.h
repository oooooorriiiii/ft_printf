/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:53:06 by ymori             #+#    #+#             */
/*   Updated: 2021/03/23 18:36:13 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PF_UTILS_H 
# define FT_PF_UTILS_H 

# define CAPSFLAG		0x00000001
# define SIGNEDFLAG		0x00000002
# define LEFTFORMATFLAG	0x00000004
# define LEADZEROFLAG	0x00000008
# define SHOWSIGNFLAG	0x00000010
# define ALTFLAG		0x00000020

/* ft_pf_format.c */
int character_format(va_list *ap);
int string_format(va_list *ap, int flags, int width, int prec);
int	num_format(const char **fmt, va_list *ap, int flags, int width, int prec);
int formatting(const char **fmt, va_list *ap, int flags, int width, int prec, int print_len);

/* ft_pf_parser.c*/
int is_flag_width_prec(const char c);

/* ft_pf_flag.c*/
int flag_checker(const char **fmt, int flags, int width);

/* ft_pf_width.c*/
int width_checker(const char **fmt, va_list *ap, int *flags, int width);

/* ft_pf_prec.c*/
int prec_checker(const char **fmt, va_list *ap, int prec);

/* ft_output.c */
int plain_text_print(const char **c, int print_len);
int percent_printed(const char **fmt);
int out_putchar(const char *s, int flags, int width, int prec);

/* ft_pf_dec.c*/
int dec_format(const char **fmt, va_list *ap, int flags, int width, int prec);

/* ft_pf_hex.c*/
int hex_format(const char **fmt, va_list *ap, int flags, int width, int prec);
char *to_hex_string(char *buf, unsigned long long n, int flag, int str_len);

/* ft_pf_ptr.c*/
int ptr_format(va_list *ap, int flags, int width, int prec);

#endif 
