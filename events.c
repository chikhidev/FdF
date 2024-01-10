#include "./includes/header.h"

// void    zoom_in(t_hooks *hooks)
// {
//     hooks->scale += 1;
    
// }

void    move_x_axis(t_hooks *hooks, double step)
{
    hooks->x_offset += step;
}

void    move_y_axis(t_hooks *hooks, double step)
{
    hooks->y_offset += step;
}

void rotate_x(t_hooks *hooks, double angle)
{
    if (angle > 360 || angle < -360)
    {
        angle = 0;
        hooks->x_angle = 0;
    }
    angle = angle * M_PI / 180;

    double temp1 = hooks->base_cartis[1];
    double temp2 = hooks->base_cartis[2];

    hooks->base_cartis[1] = temp1 * cos(angle) + temp2 * sin(angle);
    hooks->base_cartis[2] = -temp1 * sin(angle) + temp2 * cos(angle);
}

#include <math.h>

void rotate_y(t_hooks *hooks, double angle)
{
    if (angle > 360 || angle < -360)
    {
        angle = 0;
        hooks->y_angle = 0;
    }
    angle = angle * M_PI / 180;

    double temp0 = hooks->base_cartis[0];
    double temp1 = hooks->base_cartis[1];
    double temp2 = hooks->base_cartis[2];
    double temp3 = hooks->base_cartis[3];
    double temp4 = hooks->base_cartis[4];
    double temp5 = hooks->base_cartis[5];

    hooks->base_cartis[0] = temp0 * cos(angle) + temp2 * sin(angle);
    hooks->base_cartis[1] = temp1;
    hooks->base_cartis[2] = -temp0 * sin(angle) + temp2 * cos(angle);
    hooks->base_cartis[3] = temp3 * cos(angle) + temp5 * sin(angle);
    hooks->base_cartis[4] = temp4;
    hooks->base_cartis[5] = -temp3 * sin(angle) + temp5 * cos(angle);
}


int render_next_frame(t_hooks *hooks)
{
    mlx_destroy_image(hooks->mlx, hooks->img.img);
    refresh_image(hooks, &hooks->img);
    mark_points(hooks);
    mlx_put_image_to_window(
							hooks->mlx, hooks->win,
							hooks->img.img, 0, 0);
	show_guide(hooks);
    return (0);
}

// int show_cartesian(t_hooks *hooks)
// {
//     draw_cartesian(&hooks->img, hooks);
//     mlx_put_image_to_window(hooks->display->mlx, hooks->display->win, hooks->img->img, 0, 0);
//     return (0);
// }

int	key_listener(int keycode, t_hooks *hooks)
{
    if (keycode == 53)
    {
        printf("Bye\n");
        exit_free(hooks);
    }
    else if (keycode == 2)
    {
        hooks->y_angle += .1;
        rotate_y(hooks, hooks->y_angle);
        render_next_frame(hooks);
    }
    else if (keycode == 0)
    {
        hooks->y_angle -= .1;
        rotate_y(hooks, hooks->y_angle);
        render_next_frame(hooks);
    }
    else if (keycode == 13)
    {
        rotate_x(hooks, hooks->x_angle += 1);
        render_next_frame(hooks);
    }
    else if (keycode == 1)
    {
        rotate_x(hooks, hooks->x_angle -= 1);
        render_next_frame(hooks);
    }
    else if (keycode == 6)
    {
        hooks->scale += .2;
        render_next_frame(hooks);
    }
    else if (keycode == 7)
    {
        hooks->scale -= .2;
        render_next_frame(hooks);
    }
    else if (keycode == 35)
    {
        move_x_axis(hooks, 10);
        render_next_frame(hooks);
    }
    else if (keycode == 31)
    {
        move_x_axis(hooks, -10);
        render_next_frame(hooks);
    }
    else if (keycode == 15)
    {
        config_hooks(hooks);
        render_next_frame(hooks);
    }
    else if (keycode == 37)
    {
        hooks->allow_link = !hooks->allow_link;
        render_next_frame(hooks);
    }
    printf("keycode is %d\n", keycode);
	return (0);
}

int zoom_handle(int keycode, t_hooks *hooks)
{
    (void)keycode;
    (void)hooks;
    
    return (0);
}

