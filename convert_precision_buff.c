#include "headers/ft_printf.h"
#include "headers/libft.h"

char	*convert_from_flag(char cflag, va_list vargs)
{
	if (is_valid_param(cflag, "diu"))
	{
		if (cflag == 'u')
			return (convert_u(va_arg(vargs, unsigned int)));
		return (convert_d_i(va_arg(vargs, int)));
	}
	if (cflag == 's')
		return (convert_s(va_arg(vargs, char *)));
	if (cflag == 'c')
		return (convert_c(va_arg(vargs, char)));
	if (cflag == 'p')
		return (convert_p(va_arg(vargs, void *), "0123456789abcdef"));
	if (cflag == 'x')
		return (convert_x(va_arg(vargs, unsigned int), "0123456789abcdef"));
	if (cflag == 'X')
		return (convert_X(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
	if (cflag == '%')
		return ("%");
	return (NULL);
}

void	convert_precision_buffer(prt_t * object)
{
	char	*bzeroes;
	char	*new_buff;

	if (object->buffer && object->precision)
	{
		if (is_valid_param(object->cflag, "diuxX"))
		{
			if (ft_strlen(object->buffer) < object->precision)
			{
				bzeroes = malloc(sizeof(char) * object->precision + 1);
				if (!bzeroes)
					return ;
				ft_memset(bzeroes, '0', object->precision - ft_strlen(object->buffer));
				bzeroes[object->precision - ft_strlen(object->buffer)] = 0;
				new_buff = ft_strjoin(bzeroes, object->buffer);
				free(object->buffer);
				free(bzeroes);
				object->buffer = new_buff; 
			}
		}
		else if (is_valid_param(object->cflag, "s"))
		{
			if (ft_strlen(object->buffer) > object->precision)
			{
				new_buff = ft_substr(object->buffer, 0, object->precision);
				free(object->buffer);
				object->buffer = new_buff;
			}
		}
	}
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	*s = argv[1];
		char	*varg = argv[2];
		char	*sval;
		char	cflag = get_cflag(s+1);
		if (!cflag)
		{
			printf("Error. Invalid or absent flag.\n");
			return 0;
		}
		sval = convert_s(varg);
		char	*flags = get_flags(s+1);
		char	*lflags = parse_legal_flags(flags, cflag);
		unsigned int range = get_range(s+1);
		unsigned int precision = get_precision(s+1);
		prt_t * object = init_params((void *)sval, lflags ,range, precision);
		printf("object->cflag=%c\nobject->buffer=\"%s\"\nobject->flags=%s\nobject->range=%d\nobject->precision=%d\n", object->cflag, (char *)object->buffer, object->flags, object->fwidth, object->precision);
		convert_precision_buffer(object);
		printf("New converted buffer after precision check: %s\n", object->buffer);
		free_prt_t(object);
	}
	return 0;
}
