#include "fractol.h"

void    my_pixel_put(int x,  int y, t_img *img,  int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

unsigned int get_color(int i, t_fractal *fractal)
{
    unsigned int color_palette[23];

    color_palette[0] = 0x9400D3;   // Light Goldenrod Yellow
    color_palette[1] = 0xFFFF00;   // Yellow
    color_palette[2] = 0xFFD700;   // Gold
    color_palette[3] = 0xDAA520;   // Goldenrod
    color_palette[4] = 0x7FFF00;   // Chartreuse
    color_palette[5] = 0x32CD32;   // Lime Green
    color_palette[6] = 0x008000;   // Green
    color_palette[7] = 0x006400;   // Dark Green
    color_palette[8] = 0x0000FF;    // Blue
    color_palette[9] = 0x00BFFF;    // Deep Sky Blue
    color_palette[10] = 0x4169E1;    // Royal Blue
    color_palette[11] = 0x87CEEB;    // Sky Blue
    color_palette[12] = 0x4682B4;    // Steel Blue
    color_palette[13] = 0x6495ED;    // Cornflower Blue
    color_palette[14] = 0x1E90FF;    // Dodger Blue
    color_palette[15] = 0x00CED1;    // Dark Turquoise
    color_palette[16] = 0x7FFFD4;    // Aquamarine
    color_palette[17] = 0xB0E0E6;    // Powder Blue
    color_palette[18] = 0xF0FFFF;   // Azure
    color_palette[19] = 0xE0FFFF;   // Light Cyan
    color_palette[20] = 0xFFFFFF;   // White
    color_palette[21] = 0xF5F5DC;   // Beige
    color_palette[22] = 0xFFE4B5;   // Moccasin
    return (color_palette[(i + (fractal->iterations / 5)) % 23] + (i * 0x010201));
}

static void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;
    
    i = 0;
    z.x = 0.0;
    z.y = 0.0;
    c.x = map_x(x, -2.2, 1, WIDTH, fractal);
    c.y = map_y(y, -1.5, 1.5, HEIGHT, fractal);
    while (i < fractal->iterations)
    {
        z = sum_complex(sqr_complex(z), c);
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

void    render_mandelbrot(t_fractal *fractal)
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
