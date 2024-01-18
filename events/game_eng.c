#include "./events.h"

/*
    directions:
    0: up
    1: right
    2: down
    3: left
*/

int is_safe_around_chunk(t_hooks *hooks, int x, int y)
{
    int i;
    int j;

    i = 0;
    printf("searching in x: %d, y: %d\n", x, y);
    while (y < hooks->height_grid && i < 20)
    {
        j = 0;
        while (x < hooks->width_grid && j < 20)
        {
            if (!(ft_atoi(hooks->matrix[x][y]) > 0 && ft_atoi(hooks->matrix[x][y]) < 10))
                return (0);
            j++;
        }
        y++;
        i++;
    }
    return (1);
}

void    choose_right_pos(t_hooks *hooks, t_point *character)
{
    int     i;
    int     j;

    i = 0;
    while (i < hooks->height_grid)
    {
        j = 0;
        while (j < hooks->width_grid)
        {
            if (is_safe_around_chunk(hooks, j, i))
            {
                character->x = j * hooks->x_factor;
                character->y = i * hooks->y_factor;
                return ;
            }
            j+=20;
        }
        i+=20;
    }
}

void    spawn_character(t_hooks *hooks, t_game *game, t_point *character)
{
    choose_right_pos(hooks, character);
    get_real_point(hooks, character);
    mlx_put_image_to_window(hooks->mlx, hooks->win, game->character_img,
        hooks->x_center, hooks->y_center);
}

void    character_state(t_hooks *hooks, t_game *game, int direction)
{
    if (direction == 0)
        game->character_z = 0;
    else if (direction == 1)
        game->character_z = 1;
    else if (direction == 2)
        game->character_z = 2;
    else if (direction == 3)
        game->character_z = 3;
    else
        return ;
    render_next_frame(hooks);
}

void    setup_game(t_hooks *hooks)
{
    t_game  game;
    t_point character;

    spawn_character(hooks, &game, &character);
    game.character = &character;
    ft_printf("character_x: %d\n", game.character->x);
    ft_printf("character_y: %d\n", game.character->y);
    // game.character_img = mlx_xpm_file_to_image(
    //     hooks->mlx, "./assets/character.xpm", &game.character_x, &game.character_y);
    // game.can_move = 1;
    // game.is_save_to_move = 1;
    // game.character_z = 0;
}