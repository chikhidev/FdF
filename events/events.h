#ifndef EVENTS_H
# define EVENTS_H
# include    "../includes/header.h"

int     event_listener(int keycode, t_hooks *hooks);
int     render_next_frame(t_hooks *hooks);
void    reset_exit_handler(t_hooks *hooks, int keycode);
void    link_cart_handler(t_hooks *hooks, int keycode);
void    handle_moving(t_hooks *hooks, int keycode);
void    handle_scaling(t_hooks *hooks, int keycode);
void    handle_z_scaling(t_hooks *hooks, int keycode);
void    handle_xy_scaling(t_hooks *hooks, int keycode);

# endif