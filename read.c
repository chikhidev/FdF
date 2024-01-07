/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:58:54 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/25 08:29:54 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include "./includes/string_utils.h"

void    free_matrix(t_hooks *hooks)
{
    int j;
    int i;

    i = hooks->grid.height_grid - 1;
    while (i >= 0)
    {
        j = hooks->grid.width_grid - 1;
        while (j >= 0)
            ft_free((void **)&hooks->matrix[i][j--]);
        ft_free((void **)hooks->matrix[i]);
        i--;
    }
    ft_free((void **)hooks->matrix);
}
 
int	read_fdf(int fd, t_hooks *hooks, t_grid *grid)
{
	char	*line;
	char	**single_line_matrice;
	int		temp_cols;
	int		line_idx;

	hooks->matrix = NULL;
	line = ft_strtrim(get_next_line(fd), "\n");
	line_idx = 0;
	while (line)
	{
		single_line_matrice = ft_split(line, ' ');
        ft_free((void**)&line);

		temp_cols = cols_count(single_line_matrice);
		if (temp_cols != grid->width_grid && grid->height_grid != 0)
        {
            print_error(ft_strjoin(ft_strjoin(
                    "Map grid error at line ", ft_itoa(grid->height_grid + 1)), "\n"),0);
            free_matrix(hooks);
			return (0);
        }
        grid->width_grid = temp_cols;
        grid->height_grid++;
        hooks->matrix = ft_realloc(hooks->matrix,
                line_idx * sizeof(char **), (line_idx + 1) * sizeof(char **));
        if (!hooks->matrix)
            return (print_error("Error found while loading the map\n", 0));
        hooks->matrix[line_idx++] = single_line_matrice;
        line = ft_strtrim(get_next_line(fd), "\n");
	}
	return (1);
}

t_point *generate_map(t_hooks *hooks)
{
    t_point *head_point;
    int     i;
    int     j;

    head_point = NULL;
    i = 0;
    write(1, "Generating...\n", 15);
    while(i < hooks->grid.height_grid)
    {
        j = 0;
        while (j < hooks->grid.width_grid)
        {
            add_point(&head_point, new_point(
                i * ( WIDTH / hooks->grid.width_grid / 3),
                j * ( WIDTH / hooks->grid.height_grid / 3),
                ft_atoi((const char*)hooks->matrix[i][j])
            ));
            // printf("point (%d, %d, %d) created\n", 
            //     i * ( WIDTH / hooks->grid.width_grid / 3),
            //     j * ( WIDTH / hooks->grid.height_grid / 3),
            //     ft_atoi((const char*)hooks->matrix[i][j])
            // );
            j++;
        }
        i++;
    }
    return (head_point);
}

int load_map(t_hooks *hooks, char *file, t_grid *grid)
{
    int		fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        return (print_error("Map file not found\n", 0));
    }
	grid->width_grid = 0;
    grid->height_grid = 0;
    if (read_fdf(fd, hooks, grid) == 0)
        return (0);
    hooks->space_points = generate_map(hooks);
    free_matrix(hooks);
    return (1);
}
