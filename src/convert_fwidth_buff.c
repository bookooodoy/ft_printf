/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fwidth_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:21:04 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 19:44:31 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

int	convert_fwidth_negative(t_prt *object)
{
	int	i;

	i = 0;
	if (ft_putstr(object->buffer) == -1)
		return (-1);
	while (i < (size_t)object->fwidth - ft_strlen(object->buffer))
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		i++;
	}
	return (i + ft_strlen(object->buffer));
}

int	convert_fwidth_nflag(t_prt *object);
{
	while (i < (size_t)object->fwidth - ft_strlen(object->buffer))
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		i++;
	}
	if (ft_putstr(object->buffer) == -1)
		return (-1);
	return (i + ft_strlen(object->buffer));
}

int	convert_fwidth_buffer(t_prt *object)
{
	if (object->buffer && object->fwidth)
	{
		if (is_valid_param('-', object->flags) && object->cflag != '%')
			convert_fwidth_negative(object);
		else if (object->buffer && object->fwidth)
			convert_fwidth_nflag(object);
	}
	return (ft_strlen(object->buffer));
}
