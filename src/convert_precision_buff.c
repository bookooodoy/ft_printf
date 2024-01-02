/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision_buff.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:07 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:25 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

unsigned int	get_precision(char *s)
{
	unsigned int	i;
	unsigned int	precision;

	precision = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] != '.')
		return (-1);
	++i;
	while (s[i] && ft_isdigit(s[i]))
		precision = (10 * precision) + (s[i++] - '0');
	return (precision);
}

char	*convert_from_flag(char cflag, va_list vargs)
{
	if (is_valid_param(cflag, "diu"))
	{
		if (cflag == 'u')
			return (convert_u(va_arg(vargs, unsigned int)));
		return (convert_d_i(va_arg(vargs, int)));
	}
	if (cflag == 's')
		return (convert_s(va_arg(vargs, char *)));
	if (cflag == 'c')
		return (convert_c(va_arg(vargs, int)));
	if (cflag == 'p')
		return (convert_arg_p(va_arg(vargs, void *), "0123456789abcdef"));
	if (cflag == 'x')
		return (convert_x(va_arg(vargs, unsigned int), "0123456789abcdef"));
	if (cflag == 'X')
		return (convert_x(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
	if (cflag == '%')
		return (ft_strdup("%"));
	return (NULL);
}

void	convert_precision_buffer_sflag(t_prt *object)
{
	char	*bzeroes;
	char	*new_buff;

	if (ft_strlen(object->buffer) < (size_t)object->precision)
	{
		bzeroes = malloc(sizeof(char) * object->precision + 1);
		if (!bzeroes)
			return ;
		ft_memset(bzeroes, '0', object->precision - ft_strlen(object->buffer));
		bzeroes[object->precision - ft_strlen(object->buffer)] = 0;
		new_buff = ft_strjoin(bzeroes, object->buffer);
		free(object->buffer);
		free(bzeroes);
		object->buffer = new_buff;
	}
}

void	convert_precision_buffer_digits(t_prt *object)
{
	char	*new_buff;

	if (ft_strlen(object->buffer) > (size_t)object->precision)
	{
		new_buff = ft_substr(object->buffer, 0, object->precision);
		free(object->buffer);
		object->buffer = new_buff;
	}
}

void	convert_precision_buffer(t_prt *object)
{
	if (object->buffer && object->precision != -1)
	{
		if (is_valid_param(object->cflag, "diuxX"))
			convert_precision_buffer_sflag(object);
		else if (is_valid_param(object->cflag, "s"))
			convert_precision_buffer_digits(object);
	}
}
