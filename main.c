#include "fractol.h"

static int	handle_close(t_fractal *fractal) {
    mlx_destroy_window(fractal->mlx, fractal->win);
    exit(0);
    return 0;
}

static int		handle_key_press(int keycode, t_fractal *fractal)
{
    double  move_step;

    move_step = 0.2 / fractal->zoom;
    if (keycode == 112)
        fractal->iterations += 10;
    if (keycode == 111)
        fractal->iterations -= 10;
    if (keycode == 65307)
        handle_close(fractal);
    if (keycode == 65362)
        fractal->center_y -= move_step;
    if (keycode == 65364)
        fractal->center_y += move_step;
    if (keycode == 65361)
        fractal->center_x -= move_step;
    if (keycode == 65363)
        fractal->center_x += move_step;
    if (ft_strlen(fractal->name) == 10)
        render_mandelbrot(fractal);
    if (ft_strlen(fractal->name) == 5)
        render_julia(fractal);
    if (ft_strlen(fractal->name) == 11)
        render_ship(fractal);
    return 0;
}

static int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
    double zoom_factor = 1.1;
    double fractal_x = fractal->center_x + (x - 693) 
        * (3.2 / (WIDTH * fractal->zoom));
    double fractal_y = fractal->center_y + (y - 504) 
        * (3.0 / (HEIGHT * fractal->zoom));

    if (button == 4) {  // Zoom in
        fractal->zoom *= zoom_factor;
        fractal->center_x = fractal_x - (x - 693) 
            * (3.2 / (WIDTH * fractal->zoom));
        fractal->center_y = fractal_y - (y - (HEIGHT / 2)) 
            * (3.0 / (HEIGHT * fractal->zoom));
    } else if (button == 5) {  // Zoom out
        fractal->zoom /= zoom_factor;
        fractal->center_x = fractal_x - (x - 693) 
            * (3.2 / (WIDTH * fractal->zoom));
        fractal->center_y = fractal_y - (y - (HEIGHT / 2)) 
            * (3.0 / (HEIGHT * fractal->zoom));
    }
    if (ft_strlen(fractal->name) == 10)
        render_mandelbrot(fractal);
    if (ft_strlen(fractal->name) == 5)
        render_julia(fractal);
    if (ft_strlen(fractal->name) == 11)
        render_ship(fractal);
    return (0);
}


static void set_event_hooks(t_fractal *fractal) {
    mlx_hook(fractal->win, 17, 0, handle_close, fractal);
    mlx_key_hook(fractal->win, handle_key_press, fractal);
    mlx_mouse_hook(fractal->win, mouse_hook, fractal);
} 

int main(int argc, char *argv[]) {
    t_fractal   fractal; 

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
        || (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
        || (argc == 2 && !ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])))) {
        fractal_init(&fractal);
        fractal.name = argv[1];
        if (argc == 4) {
            fractal.julia_x = atod(argv[2]);
            fractal.julia_y = atod(argv[3]);
            render_julia(&fractal);
        }
        else if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
            render_mandelbrot(&fractal);
        else
            render_ship(&fractal);
        set_event_hooks(&fractal);
        mlx_loop(fractal.mlx);
    }
    else {
        ft_putstr_fd(ERROR_MESSAGE, 2);
        return (1);
    }
    return (0);
}
