#include "fractol.h"

static void fractal_init2(t_fractal *fractal)
{
    fractal->center_x = 0.0;
    fractal->center_y = 0.0;
    fractal->zoom = 1.0;
    fractal->iterations = 42;
    fractal->img->img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->img->img_ptr)
    {
        free(fractal->img);
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        return ;
    }
    fractal->img->pixels_ptr = mlx_get_data_addr(fractal->img->img_ptr, &fractal->img->bpp, &fractal->img->line_len, &fractal->img->endian);
}   

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if(!fractal->mlx)
        return ;
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (!fractal->win)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        return ;
    }
    fractal->img = malloc(sizeof(t_img));
    if (!fractal->img)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        return ;
    }
    fractal_init2(fractal);
}