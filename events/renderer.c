#include "./events.h"

int render_next_frame(t_hooks *hooks)
{
    mlx_destroy_image(hooks->mlx, hooks->img.img);
    refresh_image(hooks, &hooks->img);
    if (hooks->show_cartesian)
        draw_cartesian(hooks);
    mark_points(hooks);
    mlx_put_image_to_window(
							hooks->mlx, hooks->win,
							hooks->img.img, 0, 0);
	show_guide(hooks);
    return (0);
}