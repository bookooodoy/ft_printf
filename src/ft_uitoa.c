/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:55:50 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:44 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	count_digit_length(unsigned int n)
{
	size_t	length;
	size_t	popo;

	length = 1;
	popo = (unsigned int)n;
	while (popo >= 10)
	{
		length++;
		popo /= 10;
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	char	*crazy;
	int		d;
	size_t	popo;

	d = count_digit_length(n);
	crazy = (char *)malloc(sizeof(char) * (d + 1));
	if (!crazy)
		return (NULL);
	if (n == 0)
		crazy[0] = '0';
	crazy[d--] = 0;
	popo = (unsigned int)n;
	while (popo != 0)
	{
		crazy[d--] = (popo % 10) + '0';
		popo /= 10;
	}
	return (crazy);
}
