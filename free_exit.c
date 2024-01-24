#include "./includes/header.h"

void    free_matrix(t_hooks *hooks)
{
    int i;
    int j;

    if (!hooks->matrix)
        return ;
    i = 0;
    while (i < hooks->height_grid)
    {
        j = 0;
        while (j < hooks->width_grid)
        {
            free(hooks->matrix[i][j]);
            hooks->matrix[i][j] = NULL;
            j++;
        }
        free(hooks->matrix[i]);
        i++;
    }
    free(hooks->matrix);
    hooks->matrix = NULL;;
}

void    free_split(char **splitted)
{
    int i;

    i = 0;
    while (splitted[i])
    {
        free(splitted[i]);
        i++;
    }
    free(splitted);
}

void	exit_free(t_hooks *hooks)
{
    free(hooks->cmd);
	free_matrix(hooks);
	mlx_destroy_image(hooks->mlx, hooks->img.img);
	mlx_destroy_window(hooks->mlx, hooks->win);
    system("leaks fdf");
	exit(0);
}

int	destroy(int keycode, t_hooks *hooks)
{
	(void)keycode;
	(void)hooks;
	ft_printf("Bye\n");
	exit(0);
	return (0);
}
