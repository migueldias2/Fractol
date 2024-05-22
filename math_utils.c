#include "fractol.h"

double	atod(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s && (*s >= '0' && *s <= '9'))
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_complex	sqr_complex(t_complex a)
{
	t_complex result;

	result.x = a.x * a.x + (-1 * (a.y * a.y));
	result.y = 2 * a.x * a.y;
	return (result);	
}

double abs_complex(t_complex c)
{
	return (sqrt(c.x * c.x + c.y * c.y));
}