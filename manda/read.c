/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:58:54 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:40:20 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int	process_line(t_hooks *hooks, int fd)
{
	char	*line;
	char	**single_line_matrice;
	int		temp_cols;

	hooks->tmp_string = get_next_line(fd);
	if (!hooks->tmp_string)
		return (0);
	line = ft_strtrim(hooks->tmp_string, "\n");
	free(hooks->tmp_string);
	single_line_matrice = ft_split(line, ' ');
	free(line);
	if (!single_line_matrice)
		print_error("an error appeared while generating\n", 1);
	temp_cols = cols_count(single_line_matrice, hooks);
	free_split(single_line_matrice);
	if (temp_cols != hooks->width_grid && hooks->height_grid != 0)
	{
		ft_printf("Map grid error at line %d\n", hooks->height_grid + 1);
		ft_printf("Expected %d columns, got %d\n", hooks->width_grid,
			temp_cols);
		exit(1);
	}
	hooks->width_grid = temp_cols;
	hooks->height_grid++;
	return (1);
}

int	read_fdf(t_hooks *hooks, int fd)
{
	ft_printf("-> Reading the map and validating...\n");
	while (process_line(hooks, fd))
	{
		if (hooks->width_grid == 0)
			print_error("Bad grid\n", 1);
		if (hooks->width_grid < 0 || hooks->height_grid < 0)
			print_error("Map too large, can't deal with it\n", 1);
	}
	if (hooks->width_grid * hooks->height_grid > 50000)
		ft_printf("|\n -- Map is large\n\n\n");
	return (1);
}

void	generate_map(t_hooks *hooks, int fd)
{
	char	*line;
	int		i;

	hooks->matrix = malloc(sizeof(char **) * hooks->height_grid);
	if (!hooks->matrix)
		print_error("matrix not allocated (memory problems)\n", 1);
	i = 0;
	ft_printf("Generating %d points...\n", hooks->width_grid
		* hooks->height_grid);
	line = get_next_line(fd);
	while (line)
	{
		hooks->tmp_string = ft_strtrim(line, "\n");
		if (!hooks->tmp_string)
			print_error("an error appeared while generating\n", 1);
		free(line);
		hooks->arr = ft_split(hooks->tmp_string, ' ');
		if (!hooks->arr)
			print_error("an error appeared while generating\n", 1);
		free(hooks->tmp_string);
		hooks->matrix[i] = hooks->arr;
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

/*get the best x and y factoring
depending on the object dimentions to fit all the screen*/
void	get_best_factoring(t_hooks *hooks)
{
	if (hooks->width_grid == 0)
		return ;
	hooks->x_factor = WIDTH / hooks->width_grid;
	hooks->y_factor = hooks->x_factor;
}

int	load_map(t_hooks *hooks, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Map file not found\n", 1);
	if (read_fdf(hooks, fd) == 0)
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	if (hooks->height_grid == 0 || hooks->width_grid == 0)
		print_error("Map is empty\n", 1);
	if (hooks->height_grid == 1 && hooks->width_grid == 1)
		print_error("You have only one point, nothing will be displayed\n", 1);
	ft_printf("range of z: [%d, %d]\n", hooks->z_max, hooks->z_min);
	if (hooks->z_max > Z_MOY || hooks->z_min < -Z_MOY)
		hooks->z_factor = 1;
	get_best_factoring(hooks);
	generate_map(hooks, fd);
	return (1);
}
