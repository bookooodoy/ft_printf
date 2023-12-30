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

void	convert_precision_buffer(prt_t * object)
{
	char	*bzeroes;
	char	*new_buff;

	if (object->buffer && object->precision)
	{
		if (is_valid_param(object->cflag, "diuxX"))
		{
			if (ft_strlen(object->buffer) < object->precision)
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
		else if (is_valid_param(object->cflag, "s"))
		{
			if (ft_strlen(object->buffer) > object->precision)
			{
				new_buff = ft_substr(object->buffer, 0, object->precision);
				free(object->buffer);
				object->buffer = new_buff;
			}
		}
	}
}
/*
#include <stdio.h>
void	print_object(prt_t * object)
{
	printf("Convert Flag=%c\nBuffer=%s\nValid Flags=%s\nRange(optional)=%u\nPrecision(optional)=%u\n\n", object->cflag, object->buffer, object->flags, object->fwidth, object->precision);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		prt_t * convs;
		prt_t * convd;
		prt_t * convx;

		int t = 126648;
	       
		convs = test(argv[1], "fils de chien");
		convd = test(argv[2], t);
		convx = test(argv[3], t);

		convert_precision_buffer(convs);
		convert_precision_buffer(convd);
		convert_precision_buffer(convx);
		append_flags(convs);
		append_flags(convd);
		append_flags(convx);

		convert_fwidth_buffer(convs);
		printf("\n");
		convert_fwidth_buffer(convd);
		printf("\n");
		convert_fwidth_buffer(convx);
		printf("\n");
		print_object(convs);
		print_object(convd);
		print_object(convx);
	}
	return 0;
}
*/
