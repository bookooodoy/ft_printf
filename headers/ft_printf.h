/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:41:05 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/18 19:13:31 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_prt
{
	char			*buffer;
	char			*flags;
	char			cflag;
	unsigned int	fwidth;
	int				precision;
}	t_prt;

unsigned int	get_uintlen(int x);
char			*convert_arg_p(void *p, char *base);
char			*convert_x(unsigned int x, char *base);
char			*convert_s(const char *s);
char			*convert_c(const char c);
char			*convert_d_i(int i);
char			*convert_u(unsigned int i);
char			*convert_from_flag(char cflag, va_list vargs);
char			*get_flags(char *s);
char			*ft_uitoa(unsigned int n);
t_prt			*init_params(char *s, va_list vargs);
int				ft_printf(const char *s, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				get_plen(void *p);
void			free_t_prt(t_prt *object);
void			convert_precision_buffer(t_prt *object);
int				convert_fwidth_buffer(t_prt *object);
void			append_flags(t_prt *object);
int				is_valid_param(const char c, const char *valid_params);
char			get_cflag(const char *s);
unsigned int	get_fwidth(char *s);
unsigned int	get_range(char *s);
unsigned int	get_precision(char *s);
char			*overwrite_flags(char *flags, char ignored);
char			*parse_legal_flags(char *flags, char cflag);

#endif
