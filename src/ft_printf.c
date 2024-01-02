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

void	free_t_prt(t_prt *object)
{
	if (!object)
		return ;
	if (*object->buffer)
		free(object->buffer);
	free(object->flags);
	free(object);
}

int	get_prt_objsize(char *s, va_list vargs)
{
	t_prt	*object;
	int		c;

	c = 0;
	object = init_params(s, vargs);
	if (!object)
		return (-1);
	if ((object->precision != -1) && (object->cflag != 'c'))
		convert_precision_buffer(object);
	if (object->flags)
		append_flags(object);
	if ((size_t)object->fwidth > ft_strlen(object->buffer))
		c = convert_fwidth_buffer(object);
	if (c == -1)
		return (free_t_prt(object), c);
	if (object->cflag == 'c')
		c = ft_putchar(*(object->buffer));
	else
		c = ft_putstr(object->buffer);
	return (free_t_prt(object), c);
}

int	ft_check_flag(char *substring, int *i, va_list vargs)
{
	int	c;

	if (!substring)
		return (-1);
	c = get_prt_objsize(substring, vargs);
	while (!is_valid_param(substring[*i], "cspdiuxX%") && substring[*i])
		*i += 1;
	return (c);
}

int	ft_printf(const char *s, ...)
{
	char	*substr;
	int		i;
	int		c;
	int		fc;
	va_list	vargs;

	va_start(vargs, s);
	i = 0;
	fc = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			substr = ft_substr(s, i+1, ft_strlen(s));
			c = ft_check_flag(substr, &i+1, vargs);
			free(substr);
		}
		else
			c = ft_putchar(s[i]);
		if (c == -1)
			return (va_end(vargs), -1);
		fc += c;
		i++;
	}
	return (va_end(vargs), fc);
}

#include <stdio.h>
#include <limits.h>
int	main(void)
{
	//int a;
	//int b;
	// flags test
	
	//char *s = "fils de putain";
	int x = -3;
	ft_printf("test %%x %#-10x", x);
	printf("\n\n");
	//b = printf("test %%c %-+10d", x);
	//printf("\n\nValues:\n\n(mine) %d\n\n(original) %d", a, b);	
	//printf("\n\n");
	return 0;
}
