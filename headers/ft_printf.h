/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:41:05 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/17 07:10:05 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct
{
	void		*buffer; 
	char		*flags;
	unsigned int	range;
	unsigned int	precision;
} prt_t;

// main functions
int     ft_printf(const char *s/*, ...*/);
int     ft_putchar(char c);

// convert functions to get the buffer of the converted value with argument
int		get_plen(void *p);
char		*convert_arg_p(void *p, char *base);
unsigned int	get_uintlen(int x);
char		*convert_x(unsigned int x, char *base);
char		*convert_s(const char *s);
char		*convert_c(const char c);
char    	*convert_d_i(int i);
char    	*convert_u(unsigned int i);

// core functions (print buffer with params and return len of printed value)
prt_t	*init_params(void *buff, char *lflags, unsigned int lrange, unsigned int isprecision);

// parsing
int		is_valid_param(const char c, const char *valid_params);
char		get_cflag(const char *s);
char		*get_flags(char *s);
unsigned int	get_range(char *s);
unsigned int    get_precision(char *s);
char	    	*overwrite_flags(char *flags, char ignored);
char    	*parse_legal_flags(char *flags, char cflag);

#endif
