#include "./includes/header.h"
#include "./events/events.h"

int	event_listener(int keycode, t_hooks *hooks)
{
    reset_exit_handler(hooks, keycode)   ;
    link_cart_handler(hooks, keycode);
    handle_scaling(hooks, keycode);
    handle_moving(hooks, keycode);
    handle_z_scaling(hooks, keycode);
    handle_xy_scaling(hooks, keycode);
    ft_printf("keycode: %d\n", keycode);
	return (0);
}
