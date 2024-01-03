/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:40:06 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:17 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	while (*s)
	{
		if (ft_putchar(*s++) == -1)
			return (-1);
		c++;
	}
	return (c);
}

char	*convert_c(const char c)
{
	char	*converted;

	converted = malloc(sizeof(char) + 1);
	if (!(converted))
		return (NULL);
	converted[0] = c;
	converted[1] = 0;
	return (converted);
}

char	*convert_s(const char *s)
{
	char	*converted;

	if (!s)
		return (NULL);
	converted = ft_strdup(s);
	if (!converted)
		return (NULL);
	return (converted);
}
