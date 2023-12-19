/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:48:23 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:29 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

unsigned int	get_uintlen(int x)
{
	unsigned int	c;

	c = 0;
	while (x > 0)
	{
		x /= 16;
		c++;
	}
	return (c);
}

char	*convert_x(unsigned int x, char *base)
{
	char	*buff;
	size_t	xsize;
	size_t	msize;

	xsize = get_uintlen(x);
	msize = xsize;
	buff = malloc(sizeof(char) * xsize + 1);
	if (!buff)
		return (NULL);
	if (x == 0)
	{
		buff[0] = '0';
		return (buff[1] = 0, buff);
	}
	while (x > 0)
	{
		buff[(--xsize)] = base[x % 16];
		x /= 16;
	}
	buff[xsize + msize] = 0;
	if (!*buff)
		return (free(buff), NULL);
	return (buff);
}
