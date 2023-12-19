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
	if (object->precision)
		convert_precision_buffer(object);
	if (object->flags)
		append_flags(object);
	if (object->fwidth > ft_strlen(object->buffer))
		c = convert_fwidth_buffer(object);
	else
		c = ft_putstr(object->buffer);
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
			substr = ft_substr(s, i+1, ft_strlen(s));
			if (!substr)
				return (-1);
			c = get_prt_objsize(substr, vargs);
			while (!(is_valid_param(s[i], "cspdiuxX") || !s[i]))
				i++;
			free(substr);
			i++;
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
	int a = ft_printf(" %-9X ", INT_MAX);
	printf("\n\n");
	int b = printf(" %-9X ", INT_MAX);
	
	printf("\n\nVALUES:\n\n(mine) = %d\n(printf) = %d\n\n", a, b);
	return 0;
}
