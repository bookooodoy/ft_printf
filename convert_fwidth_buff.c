#include "headers/ft_printf.h"
#include "headers/libft.h"

int	convert_fwidth_buffer(prt_t * object)
{
	size_t	i;
	int	c;

	c = 0;
	i = 0;
	// check if buffer and field width
	if (object->buffer && object->fwidth && (ft_strlen(object->buffer) < object->fwidth))
	{
		if (is_valid_param('-', object->flags) && object->cflag != '%')
		{
			c += ft_putstr(object->buffer);
			while (i < object->fwidth - ft_strlen(object->buffer))
			{
				c += ft_putchar(' ');
				i++;
			}
		}
		// no flags
		else if (object->buffer && object->fwidth)
		{
			while (i < object->fwidth - ft_strlen(object->buffer))
			{
				c += ft_putchar(' ');
				i++;
			}
			c += ft_putstr(object->buffer);
		}
	}
	return (c);
}
