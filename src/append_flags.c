/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:30:59 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 19:14:39 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

void	append_hashtag(char **buffer)
{
	char	*new_buff;

	new_buff = ft_strjoin("0x", *buffer);
	free(*buffer);
	*buffer = new_buff;
}

void	append_plus(char **buffer)
{
	char	*new_buff;

	new_buff = ft_strjoin("+", *buffer);
	free(*buffer);
	*buffer = new_buff;
}

void	append_space(char **buffer)
{
	char	*new_buff;

	new_buff = ft_strjoin(" ", *buffer);
	free(*buffer);
	*buffer = new_buff;
}

void	append_zeroes(char **buffer, unsigned int *fwidth)
{
	char	*new_buff;
	char	*bzeroes;

	if (ft_strlen(*buffer) < ((size_t) * fwidth))
	{
		bzeroes = malloc(sizeof(char) * (*fwidth + 2));
		if (!bzeroes)
			return ;
		ft_memset(bzeroes, '0', *fwidth - ft_strlen(*buffer));
		bzeroes[*fwidth - ft_strlen(*buffer) + 1] = 0;
		new_buff = ft_strjoin(bzeroes, *buffer);
		free(*buffer);
		free(bzeroes);
		*buffer = new_buff;
	}
}

void	append_flags(t_prt *object)
{
	if (object->buffer && object->flags && is_valid_param
		(object->cflag, "xX") && is_valid_param('#', object->flags))
		append_hashtag(&(object->buffer));
	if (object->buffer && object->flags && is_valid_param
		(object->cflag, "diu") && is_valid_param
		('+', object->flags) && ft_atoi(object->buffer) >= 0)
		append_plus(&(object->buffer));
	if (object->buffer && object->flags && is_valid_param
		(object->cflag, "diu") && is_valid_param(' ', object->flags))
		append_space(&(object->buffer));
	if (object->buffer && object->flags && object->fwidth
		&& (object->precision == -1) && is_valid_param
		(object->cflag, "diuxX") && is_valid_param('0', object->flags))
		append_zeroes(&(object->buffer), &(object->fwidth));
}
