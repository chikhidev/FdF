#include "./events.h"
#include <time.h>

//x' = x * cos(a) - y * sin(a)
//y' = x * sin(a) + y * cos(a)

void    animate_angle_update(double *angle, double step)
{
    if (step < 0 && (int)*angle == 0)
        *angle = 360;
    else if (step > 0 && (int)*angle == 360)
        *angle = 0;
    *angle += step;
}

void    view_handle(t_hooks *hooks, int keycode)
{
    if (keycode == 3)
        hooks->parallel_view = !hooks->parallel_view;
    else if (keycode == 2)
        animate_angle_update(&hooks->z_angle, 2);
    else if (keycode == 0)
        animate_angle_update(&hooks->z_angle, -2);
    else
        return;
    render_next_frame(hooks);
}
