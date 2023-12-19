/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:08 by nraymond         ###   ########.fr       */
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

int	main(void)
{
	/*
	if (argc == 7)
	{
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
	int a = ft_printf("%-1.2s\n%1.3s\n%#-1050.100x\ntest\n\n", "ceci", "est", 98775);
	int b = printf("%-1.2s\n%1.3s\n%#-1050.100x\ntest\n\n", "ceci", "est", 98775);

	printf("%d\n%d\n",a, b);
	return 0;
}
