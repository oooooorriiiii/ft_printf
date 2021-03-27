/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymori <ymori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:53:06 by ymori             #+#    #+#             */
/*   Updated: 2021/03/27 16:19:03 by ymori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_UTILS_H
# define FT_PF_UTILS_H

# define CAPSFLAG		0x00000001
# define SIGNEDFLAG		0x00000002
# define LEFTFORMATFLAG	0x00000004
# define LEADZEROFLAG	0x00000008
# define SHOWSIGNFLAG	0x00000010
# define ALTFLAG		0x00000020

typedef	struct	s_format{
	int		flags;
	int		width;
	int		prec;
}				t_format;

int				arg_print(const char **fmt, va_list *ap, int print_len);
int				flag_checker(const char **fmt, int flags, int width);
t_format		width_checker(const char **fmt, va_list *ap, t_format spc);
int				prec_checker(const char **fmt, va_list *ap, int prec);
int				character_format(va_list *ap, t_format *spc);
int				string_format(va_list *ap, t_format *spc);
int				num_format(const char **fmt, va_list *ap, t_format *spc);
int				formatting(const char **fmt, va_list *ap, t_format *spc,
							int print_len);
int				dec_format(const char **fmt, va_list *ap, t_format *spc);
int				hex_format(const char **fmt, va_list *ap, t_format *spc);
char			*to_hex_string(char *buf, unsigned long long n, int flag,
						int str_len);
int				ptr_format(va_list *ap, t_format *spc);
int				plain_text_print(const char **c, int print_len);
int				percent_printed(const char **fmt);
int				out_char(const char c, t_format *spc);
int				out_str(const char *s, t_format *spc);
int				out_nbr(const char *s, t_format *spc);

#endif
