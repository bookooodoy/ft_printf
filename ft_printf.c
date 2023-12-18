/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/18 20:31:25 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

int	get_prt_objsize(char *s, va_list vargs)
{
	// create and init the prt_t object
	prt_t * object;
	int	c;

	c = 0;
	object = init_params(s, vargs);
	// check if any flag, flag combination or cflag is invalid, return -1 if invalid
	if (!object)
		return (-1);
	// if all valid
	// append possible flags
	append_flags(object);
	// if precision, update the buffer
	if (object->precision)
		convert_precision_buffer(object);
	// if fwidth, print and return size
	if (object->fwidth)
		c += convert_fwidth_buffer(object);
	// else print the buffer
	else
		c += ft_putstr(object->buffer);
	// free the buffer and object
	free_prt_t(object);
	// return the size
	return (c);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	c;
	char	*substr;
	va_list vargs;

	va_start(vargs, s);
	c = i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		
		if (s[i] == '%')
		{
			substr = ft_substr(s, i+1, ft_strlen(s));
			c += get_prt_objsize(substr, vargs);
			i++;
			while (!is_valid_param(s[i], "cspdiuxX%"))
				i++;
			free(substr);
		}
		else
			c += ft_putchar(s[i]);
		i++;
	}
	return (va_end(vargs), c);
}

/*
int	main(void)
{
	ft_printf("%1.1x lalala\n%120duuuai\n%-100.2s\n", 1253, 124, "ceci est un test");
	return 0;
}
*/
