#include "fractol.h"

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;
    
    i = 0;
    z.x = 0.0; 
    z.y = 0.0;
    c.x = map_x(x, -2.2, 1, WIDTH, fractal);
    c.y = map_y(y, -1.5, 1.5, HEIGHT, fractal);
    while (i < fractal->iterations)
    {
        z = sum_complex(sqr_complex((t_complex){fabs(z.x), fabs(z.y)}), c);
        if (abs_complex(z) > 2)
        {
            color = get_color(i, fractal);
            my_pixel_put(x, y, fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, fractal->img, 0x000000);
}

void render_ship(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            handle_pixel(x, y, fractal);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img->img_ptr, 0, 0);
}
