/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fwidth_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:21:04 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:19 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

int	convert_fwidth_buffer(prt_t * object)
{
	size_t	i;
	int	c;

	c = 0;
	i = 0;
	// check if buffer and field width
	if (object->buffer && object->fwidth && ((ft_strlen(object->buffer) < object->fwidth)))
	{
		if (is_valid_param('-', object->flags) && object->cflag != '%')
		{
			c += ft_putstr(object->buffer);
			while (i < object->fwidth - ft_strlen(object->buffer))
			{
				c += ft_putchar(' ');
				i++;
			}
		}
		// no flags
		else if (object->buffer && object->fwidth)
		{
			while (i < object->fwidth - ft_strlen(object->buffer))
			{
				c += ft_putchar(' ');
				i++;
			}
			c += ft_putstr(object->buffer);
		}
	}
	return (c);
}
