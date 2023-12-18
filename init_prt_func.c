/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prt_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:13:37 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/17 07:47:40 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

prt_t	*init_params(char *s, va_list vargs)
{
	prt_t * object;
	char	*flags;

	object = malloc(sizeof(prt_t));
	if (!object)
		return (NULL);
	object->cflag = get_cflag(s);
	flags = get_flags(s);
	object->flags = parse_legal_flags(flags, object->cflag);
	object->fwidth = get_range(s);
	object->precision = get_precision(s);
	object->buffer = convert_from_flag(cflag, vargs);
	return (object);
}

void	free_prt_t(prt_t * object)
{
	free(object->buffer);
	free(object);
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
