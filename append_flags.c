/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:30:59 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/18 20:18:58 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

void	append_flags(prt_t * object)
{
	char	*new_buff;
	char	*bzeroes;

	// will modify the buffer in place
	// # flag with x and X
	if (object->buffer && object->flags && is_valid_param(object->cflag, "xX") && is_valid_param('#', object->flags))
	{
		new_buff = ft_strjoin("0x", object->buffer);
		free(object->buffer);
		object->buffer = new_buff;
	}
	// check for + flag
	if (object->buffer && object->flags && is_valid_param(object->cflag, "diu") && is_valid_param('+', object->flags))
	{
		new_buff = ft_strjoin("+", object->buffer);
		free(object->buffer);
		object->buffer = new_buff;
	}
	// check for space flag
	if (object->buffer && object->flags && is_valid_param(object->cflag, "diu") && is_valid_param(' ', object->flags))
	{
		new_buff = ft_strjoin(" ", object->buffer);
		free(object->buffer);
		object->buffer = new_buff;
	}
	// check for '0' flag
	if (object->buffer && object->flags && object->fwidth && !object->precision && is_valid_param(object->cflag, "diuxX") && is_valid_param('0', object->flags))
	{
		if (ft_strlen(object->buffer) < object->fwidth)
		{
			bzeroes = malloc(sizeof(char) * object->fwidth + 1);
			if (!bzeroes)
				return ;
			ft_memset(bzeroes, '0', object->fwidth - ft_strlen(object->buffer));
			new_buff = ft_strjoin(bzeroes, object->buffer);
			free(object->buffer);
			free(bzeroes);
			object->buffer = new_buff;
		}
	}
}
