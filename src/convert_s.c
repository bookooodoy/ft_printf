/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:35:43 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 18:53:27 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

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
