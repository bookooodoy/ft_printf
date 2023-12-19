/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prt_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:13:37 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/18 19:18:55 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

void	free_prt_t(prt_t * object)
{
	free(object->buffer);
	free(object->flags);
	free(object);
}

prt_t	*init_params(char *s, va_list vargs)
{
	prt_t * object;
	char	*flags;

	object = malloc(sizeof(prt_t));
	if (!object)
		return (NULL);
	object->cflag = get_cflag(s);
	if (!object->cflag)
		return (NULL);
	flags = get_flags(s);
	if (flags)
	{
		object->flags = parse_legal_flags(flags, object->cflag);
		if (!object->flags)
			return (free_prt_t(object), NULL);
	}
	object->fwidth = get_range(s);
	object->precision = get_precision(s);
	object->buffer = convert_from_flag(object->cflag, vargs);
	if (!object->buffer)
		return (free_prt_t(object), NULL);
	return (object);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	*s = argv[1];
		char	*varg = argv[2];
		char	*sval;
		char	cflag = get_cflag(s+1);
		if (!cflag)
		{
			printf("Error. Invalid or absent flag.\n");
			return 0;
		}
		sval = convert_s(varg);
		char	*flags = get_flags(s+1);
		char	*lflags = parse_legal_flags(flags, cflag);
		unsigned int range = get_range(s+1);
		unsigned int precision = get_precision(s+1);
		prt_t * object = init_params((void *)sval, lflags ,range, precision);
		printf("object->buffer=\"%s\"\nobject->flags=%s\nobject->range=%d\nobject->precision=%d\n", (char *)object->buffer, object->flags, object->fwidth, object->precision);
		free_prt_t(object, sval);
	}
	return 0;
}
*/
