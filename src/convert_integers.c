/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:52:21 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

char	*convert_d_i(int i)
{
	char	*converted;

	converted = ft_itoa(i);
	if (!converted)
		return (NULL);
	return (converted);
}

char	*convert_u(unsigned int i)
{
	char	*converted;

	converted = ft_uitoa(i);
	if (!converted)
		return (NULL);
	return (converted);
}
