/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 20:55:57 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

#include <stdio.h>

int	get_prt_objsize(char *s, va_list vargs)
{
	prt_t * object;
	int	c;

	c = 0;
	object = init_params(s, vargs);
	if (!object)
		return (-1);
	if (object->precision && object->cflag != 'c')
		convert_precision_buffer(object);
	if (object->flags)
		append_flags(object);
	if (object->cflag == 'c')
	{
		if (object->fwidth > ft_strlen(object->buffer))
			c = convert_fwidth_buffer(object);
		else
			c = ft_putchar(*(object->buffer));
	}
	else
	{
		if (object->fwidth > ft_strlen(object->buffer))
			c = convert_fwidth_buffer(object);
		else
			c = ft_putstr(object->buffer);
	}
	return (free_prt_t(object), c);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	c;
	int	fc;
	char	*substr;
	va_list vargs;

	va_start(vargs, s);
	fc = c = i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		
		if (s[i] == '%')
		{
			if (s[i+1] == '%')
			{
				c = ft_putchar(s[i]);
				i += 2;
			}
			else
			{
				substr = ft_substr(s, i+1, ft_strlen(s));
				if (!substr)
					return (-1);
				c = get_prt_objsize(substr, vargs);
				while (!(is_valid_param(s[i], "cspdiuxX") && s[i]))
					i++;
				free(substr);
				i++;
			}
		}
		else
			c = ft_putchar(s[i++]);
		if (c < 0)
			return (va_end(vargs), -1);
		fc += c;
	}
	return (va_end(vargs), fc);
}

#include <limits.h>
int	main(void)
{
	int a;
	int b;
	// digits test
	a = ft_printf("test%d%i%u",0, INT_MAX, -2);
	printf("\n\n");
	b = printf("test%d%i%u",0, INT_MAX, -2);
	printf("\n\nValues:\n\n(mine) %d\n\n(original) %d", a, b);	
	printf("\n\n");
	return 0;
}
