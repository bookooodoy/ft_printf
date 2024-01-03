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
	if (object->flags)
		free(object->flags);
	free(object);
}

t_prt	*init_params(char *s, va_list vargs)
{
	t_prt	*object;
	char	*flags;

	object = malloc(sizeof(t_prt));
	if (!object)
		return (NULL);
	object->cflag = get_cflag(s);
	if (!object->cflag)
		return (NULL);
	flags = get_flags(s);
	if (*flags)
	{
		object->flags = parse_legal_flags(flags, object->cflag);
		if (!object->flags)
			return (free_t_prt(object), NULL);
	}
	object->fwidth = get_range(s);
	object->precision = get_precision(s);
	object->buffer = convert_from_flag(object->cflag, vargs);
	if (!object->buffer)
		return (free_t_prt(object), NULL);
	return (object);
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
	if (object->fwidth && (size_t)object->fwidth > ft_strlen(object->buffer))
	{
		c = convert_fwidth_buffer(object);
		return (free_t_prt(object), c);
	}
	if (object->cflag == 'c')
		c = ft_putchar(*(object->buffer));
	else
		c = ft_putstr(object->buffer);
	return (free_t_prt(object), c);
}

int	ft_convert_cflag(const char *s, int *i, va_list vargs)
{
	char	*substr;
	int		c;

	if (s[*i + 1] == '%')
	{
		c = ft_putchar(s[*i]);
		*i += 1;
	}
	else
	{
		substr = ft_substr(s, *i + 1, ft_strlen(s));
		if (!substr)
			return (-1);
		c = get_prt_objsize(substr, vargs);
		while (!is_valid_param(s[*i], "cspdiuxX") && s[*i])
			*i += 1;
		free(substr);
	}
	return (c);
}

int	ft_printf(const char *s, ...)
{
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
			c = ft_convert_cflag(s, &i, vargs);
		else
			c = ft_putchar(s[i]);
		if (c == -1)
			return (va_end(vargs), -1);
		fc += c;
		i++;
	}
	return (va_end(vargs), fc);
}
