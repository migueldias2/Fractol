#include "fractol.h"

double	map_x(int x, double min, double max, int scale, t_fractal *fractal)
{
    min = min / fractal->zoom + fractal->center_x;
    max = max / fractal->zoom + fractal->center_x;
	return (min + ((double)x / scale) * (max - min));
}

double	map_y(int y, double min, double max, int scale, t_fractal *fractal)
{
    min = min / fractal->zoom + fractal->center_y;
    max = max / fractal->zoom + fractal->center_y;
	return (min + ((double)y / scale) * (max - min));
}
/* double map_x(int x, double min, double max, int width, t_fractal *fractal)
{
    return fractal->center_x + (x / (double)width - 0.5) * 2.2 / fractal->zoom;
}

double map_y(int y, double min, double max, int height, t_fractal *fractal)
{
    return fractal->center_y + (y / (double)height - 0.5) * 1.5 / fractal->zoom;
} */
