/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:55:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

#include <stdio.h>
void	prt_obj(prt_t * object)
{
	printf("object->buffer=%s\nobject->cflag=%c\nobject->flags=%s\nobject->range=%d\nobject->precision=%d\n", object->buffer, object->cflag, object->flags, object->fwidth, object->precision);
}

int	get_prt_objsize(char *s, va_list vargs)
{
	// create and init the prt_t object
	prt_t * object;
	int	c;
	int	chk;

	chk = 0;
	c = 0;
	object = init_params(s, vargs);
	// check if any flag, flag combination or cflag is invalid, return -1 if invalid
	if (!object)
		return (-1);
	// if all valid
	if (object->precision)
		convert_precision_buffer(object);
	if (object->flags)
		append_flags(object);
	// if fwidth, print and return size
	if (object->fwidth)
	{
		chk = convert_fwidth_buffer(object);
		if (chk)
			return (free_prt_t(object), c + chk);
	}
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
			if (!substr)
				return (-1);
			c += get_prt_objsize(substr, vargs);
			while (!(is_valid_param(s[i], "cspdiuxX") || !s[i]))
				i++;
			free(substr);
			i++;
		}
		else
			c += ft_putchar(s[i++]);
	}
	return (va_end(vargs), c);
}

int	test(char *s, ...)
{
	va_list vargs;

	va_start(vargs, s);
	int x = get_prt_objsize(s+1, vargs);

	va_end(vargs);
	return (x);
}

int	main(void)
{
	/*
	if (argc == 7)
	{
		int	prout = 45;
		void	*p = &prout;
		test(argv[1], 'c');
		printf("\n");
		test(argv[2], 0);
		printf("\n");
		test(argv[3], 0);
		printf("\n");
		test(argv[4], p);
		printf("\n");
		test(argv[5], "grosse merde");
		printf("\n");
		test(argv[6], 15632);
		printf("\n");
	}
	*/
	ft_printf("%-1.2s\n%1.3s\n%#01050.100x\ntest", "ceci", "est", 98775);
	return 0;
}
