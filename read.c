/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:58:54 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/08 19:05:00 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include "./includes/string_utils.h"

void    free_matrix(char ***matrix, t_hooks *hooks)
{
    int i;
    int j;

    i = 0;
    while (i < hooks->grid.height_grid)
    {
        j = 0;
        while (j < hooks->grid.width_grid)
        {
            ft_free((void **)&matrix[i][j]);
            j++;
        }
        ft_free((void **)matrix[i]);
        i++;
    }
    ft_free((void **)*matrix);
} 

int	read_fdf(int fd, t_grid *grid)
{
	char	*line;
	char	**single_line_matrice;
	int		temp_cols;

	ft_printf("-> Reading the map and validating...\n");
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		single_line_matrice = ft_split(line, ' ');
        ft_free((void**)&line);
		temp_cols = cols_count(single_line_matrice);
		if (temp_cols != grid->width_grid && grid->height_grid != 0)
            return (print_error(ft_strjoin(ft_strjoin(
                    "Map grid error at line ", ft_itoa(grid->height_grid + 1)), "\n"),0));
        grid->width_grid = temp_cols;
        grid->height_grid++;
        line = ft_strtrim(get_next_line(fd), "\n");
	}
    if (grid->width_grid == 0)
        return (print_error("Map given is empty\n", 0));
    if (grid->width_grid < 0 || grid->height_grid < 0)
        return (print_error("Map too large cant deal with it\n", 0));
    if (grid->width_grid * grid->height_grid > 50000)
        ft_printf("|\n -- Map is large, it may take a while to render!!!\n\n\n");
	return (1);
}

void    generate_map(t_hooks *hooks, int fd)
{
	char	*line;
    int     i;

    hooks->matrix = malloc(sizeof(char **) * hooks->grid.height_grid);
    if (!hooks->matrix)
        print_error("matrix not allocated (memory problems)\n", 0);
    i = 0;
    ft_printf("Generating %d points...\n", hooks->grid.width_grid * hooks->grid.height_grid);
    line = get_next_line(fd);
    while(line)
    {
        hooks->tmp_string = ft_strtrim(line, "\n");
        if (!hooks->tmp_string)
            print_error("an error appeared while generating\n", 0);
        ft_free((void **)&line);
        hooks->arr = ft_split(hooks->tmp_string, ' ');
        if (!hooks->arr)
            print_error("an error appeared while generating\n", 0);
        ft_free((void **)&hooks->tmp_string);
        hooks->matrix[i] = hooks->arr;
        line = get_next_line(fd);
        i++;
    }
    ft_free((void **)&line);
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
    if (read_fdf(fd, grid) == 0)
        return (0);
	close(fd);
	fd = open(file, O_RDONLY);
    hooks->grid = *grid;
    generate_map(hooks, fd);
    return (1);
}
