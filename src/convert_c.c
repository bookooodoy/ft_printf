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

char	*convert_c(const char c)
{
	char	*converted;

	converted = malloc(sizeof(char) + 1);
	if (!(converted))
		return (NULL);
	converted[0] = c;
	converted[1] = '\0';
	return (converted);
}
