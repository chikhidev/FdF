#ifndef EVENTS_H
# define EVENTS_H
# include    "../includes/header.h"

# define FRAME_RATE 30

typedef struct s_game
{
    t_point *character;
    void    *character_img;
    int     can_move;
    int     character_x;
    int     character_y;
    int     character_z;
    int     is_save_to_move;
}            t_game;

int     event_listener(int keycode, t_hooks *hooks);
int     render_next_frame(t_hooks *hooks);
void    reset(t_hooks *hooks);
void    setup_game(t_hooks *hooks);
void    reset_exit_handler(t_hooks *hooks, int keycode);
void    link_cart_handler(t_hooks *hooks, int keycode);
void    handle_moving(t_hooks *hooks, int keycode);
void    handle_scaling(t_hooks *hooks, int keycode);
void    view_handle(t_hooks *hooks, int keycode);
void    handle_z_scaling(t_hooks *hooks, int keycode);
void    handle_xy_scaling(t_hooks *hooks, int keycode);

# endif