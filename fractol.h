#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h" 

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\"\n\t\"./fractol julia <value_1> <value_2>\"\n\t\"./fractol burningship\"\n"
# define WIDTH 1008
# define HEIGHT 1008

typedef struct s_complex
{
    double x;
    double y;
}               t_complex;

typedef struct  s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}               t_img;

typedef struct  s_fractal
{
    int iterations;
    char    *name;
    void    *mlx;
    void    *win;
    t_img   *img;
    double  julia_x;
    double  julia_y;
    double  center_x;
    double  center_y;
    double  zoom;
}               t_fractal;

void    fractal_init(t_fractal *fractal);
double	map_y(int y, double min, double max, int scale, t_fractal *fractal);
double	map_x(int x, double min, double max, int scale, t_fractal *fractal);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	sqr_complex(t_complex a);
void    render_mandelbrot(t_fractal *fractal);
void    render_julia(t_fractal *fractal);
void    render_ship(t_fractal *fractal);
double abs_complex(t_complex c);
unsigned int get_color(int iterations, t_fractal *fractal);
void    my_pixel_put(int x,  int y, t_img *img,  int color);
double	atod(char *s);

#endif