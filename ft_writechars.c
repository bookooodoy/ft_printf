/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:46:58 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/18 16:59:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	c;
	int	fc;

	fc = 0;
	c = 0;
	while (*s)
	{
		c = ft_putchar(*s++);
		if (c > 0)
			fc += c;
		else
			return (-1);
	}
	return (c);
}
