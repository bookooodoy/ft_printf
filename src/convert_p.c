/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 01:30:41 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:23 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

int	get_plen(void *p)
{
	size_t	psize;
	int	c;

	c = 0;
	psize = ((size_t)p);
	if (psize == (size_t)NULL)
		return (c);
	while (psize > 0)
	{
		psize /= 16;
		c++;
	}
	return (c + 2);
}

char	*convert_arg_p(void *p, char *base)
{
	char		*buff;
	size_t		psize;
	size_t		csize;
	int		i;

	i = 0;
	psize = get_plen(p);
	csize = (size_t)p;
	if (!psize)
		return (NULL);
	buff = malloc(sizeof(char) * psize + 1);
	if (!buff)
		return (NULL);
	while (csize > 0)
	{
		if (i == 0)
		{
			buff[i++] = '0';
			buff[i++] = 'x';
		}
		buff[(psize + 1) - i++] = base[csize % 16];
		csize /= 16;
	}
	buff[i] = 0;
	return (buff);
}
/*
int	main(void)
{
	void	*pa = NULL;
	
	printf("%s\n%p\n", convert_arg_p(pa, "0123456789abcdef"), pa);
	free(pa);
	return 0;
}*/
