/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:08:41 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/19 20:54:12 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../inc/libft/libft.h"

int	is_valid_param(const char c, const char *valid_params)
{
	int	i;

	i = 0;
	if (!valid_params)
		return (i);
	while (valid_params[i])
	{
		if (valid_params[i] == c && valid_params[i])
			return (1);
		i++;
	}
	return (0);
}

char	get_cflag(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (is_valid_param(s[i], "cspdiuxX%"))
		return (s[i]);
	while (s[i] && is_valid_param(s[i], " -+0#"))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (!(is_valid_param(s[i], "cspdiuxX")))
			return (0);
		return (s[i]);
	}
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (!(is_valid_param(s[i], "cspdiuxX")))
		return (0);
	return (s[i]);
}

char	*get_flags(char *s)
{
	char	*flags;
	int		i;
	int		c;
	size_t		k;

	i = 0;
	c = 0;
	flags = malloc(sizeof(char) * 6);
	if (!flags)
		return (NULL);
	while (s[i] && is_valid_param(s[i], " -+0#"))
	{
		k = i + 1;
		while (s[k] && k <= ft_strlen(s))
		{
			if (is_valid_param(s[k], "cspdiuxX"))
				break ;
			if (s[i] != '0' && s[i] == s[k])
				return (free(flags), NULL);
			k++;
		}
		flags[c++] = s[i++];
	}
	flags[c] = '\0';
	if (!*flags)
		return (free(flags), NULL);
	return (flags);
}

unsigned int	get_range(char *s)
{
	unsigned int	range;
	int		i;

	i = 0;
	range = 0;
	if (!s)
		return (0);
	while ((s[i] && !ft_isdigit(s[i])) || (s[i] && s[i] == '0'))
	{
		if (s[i] == '.')
			return (0);
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
		range = (10 * range) + (s[i++] - '0');
	return (range);
}

unsigned int	get_precision(char *s)
{
	int		i;
	unsigned int	precision;

	precision = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] != '.')
		return (-1);
	++i;
	while (s[i] && ft_isdigit(s[i]))
		precision = (10 * precision) + (s[i++] - '0');	
	return (precision);
}

char	*overwrite_flags(char *flags, char ignored)
{
	char	*ov_flags;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (!flags)
		return (NULL);
	ov_flags = malloc(sizeof(char) * ft_strlen(flags) - 1);
	if (!ov_flags)
		return (NULL);
	while (flags[i])
	{
		if (flags[i] != ignored)
			ov_flags[c++] = flags[i];
		i++;
	}
	ov_flags[c] = 0;
	free(flags);
	return (ov_flags);
}

char	*parse_legal_flags(char *flags, char cflag)
{
	int	i;

	i = 0;
	if (!cflag || !flags)
		return (NULL);
	while (flags[i])
	{
		if (cflag == 'i' || cflag == 'd' || cflag == 'u')
		{
			if (!is_valid_param(flags[i], "-+ 0"))
				return (free(flags), NULL);
		}
		if (cflag == 'x' || cflag == 'X')
		{
			if (!is_valid_param(flags[i], "-0#"))
				return (free(flags), NULL);
		}
		if (cflag == 'c' || cflag == 's' || cflag == 'p')
		{
			if (!is_valid_param(flags[i], "-"))
				return (free(flags), NULL);
		}
		i++;
	}
	if (is_valid_param('0', flags) && is_valid_param('-', flags))
		flags = overwrite_flags(flags, '0');
	if (is_valid_param('+', flags) && is_valid_param(' ', flags))
		flags = overwrite_flags(flags, ' ');
	return (flags);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		char cflag = get_cflag(s+1);
		printf("CFLAG = %c\n", cflag);
		char *flags = get_flags(s+1);
		printf("FLAGS = %s\n", flags);
		printf("RANGE = %d\n", get_range(s+1));
		printf("PRECISION = %d\n", get_precision(s+1));
		printf("PARSED_FLAGS = %s\n", parse_legal_flags(flags, cflag));
	}
	return 0;
}
*/
