/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:55:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/17 00:29:07 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct
{
	void		*string; 
	char		*flags;
	char		*legal_flags;
	char		convertflag;
	unsigned int	range;
	unsigned int	precision;
} prt_t;

// main functions
int     ft_printf(const char *s, ...);
int     ft_putchar(char c);

// libft functions to remove and compile with the other header after libft is corrected
int     ft_strlen(char *c);
int     ft_isdigit(char c);

// parsing

int		is_valid_param(const char c, const char *valid_params);
char		get_cflag(const char *s);
char		*get_flags(char *s);
unsigned int	get_range(char *s);
unsigned int    get_precision(char *s);
char    *overwrite_flags(char *flags, char ignored);
char    *parse_legal_flags(char *flags, char cflag);


#endif
