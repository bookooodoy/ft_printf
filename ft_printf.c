/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/16 19:08:09 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int	i;
	int	c;
	int	fc;
	va_list vargs;

	va_start(s);
	fc = c = i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			c = init_flag(s+i, vargs);
			if (c == -1)
				return (0);
			c += fc;
			i += fc;
		}
		else
		{
			c = ft_putchar(s[i]);
			if (c == -1)
				return (0);
			fc += c;
			i++;
		}
	}
	return (va_end(vargs), fc);
}

int	main(void)
{
	return 0;
}
