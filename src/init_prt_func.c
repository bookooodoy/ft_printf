/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prt_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:13:37 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 20:51:32 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

t_prt	*init_params(char *s, va_list vargs)
{
	t_prt	*object;
	char	*flags;

	object = malloc(sizeof(t_prt));
	if (!object)
		return (NULL);
	//printf("\nno malloc error\nstring = %s\n", s);
	object->cflag = get_cflag(s);
	if (!object->cflag)
		return (NULL);
	//printf("no cflag error\nflag = %c\n", object->cflag);
	flags = get_flags(s);
	if (*flags)
	{
		//printf("no flags error (yet)\nflags = %s\n", object->flags);
		object->flags = parse_legal_flags(flags, object->cflag);
		if (!object->flags)
			return (free_t_prt(object), NULL);
		//printf("no parsed flags error)\nflags = %s\n", object->flags);
	}
	object->fwidth = get_range(s);
	object->precision = get_precision(s);
	object->buffer = convert_from_flag(object->cflag, vargs);
	if (!object->buffer)
		return (free_t_prt(object), NULL);
	//printf("no buffer error\nbuffer = %s\n", object->buffer);
	return (object);
}
