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

// int	read_fdf(int fd, t_hooks *hooks, t_grid *grid)
// {
// 	char	*line;
// 	char	**single_line_matrice;
// 	int		temp_cols;
// 	int		line_idx;

// 	hooks->matrix = NULL;
// 	line = ft_strtrim(get_next_line(fd), "\n");
// 	line_idx = 0;
// 	while (line)
// 	{
// 		single_line_matrice = ft_split(line, ' ');
// 		temp_cols = cols_count(single_line_matrice);
// 		printf("line=> %s$\n", line);
// 		if (temp_cols != grid->width_grid && line_idx != 0)
// 			return (0);
// 		grid->width_grid = temp_cols;

// 		printf("len of each line is: %d\n", grid->width_grid);
// 		printf("line is:\n");
// 		for (int i = 0; single_line_matrice[i]; i++)
// 			printf("\t%s[%d]\n", single_line_matrice[i], i);

// 		line = ft_strtrim(get_next_line(fd), "\n");
// 		line_idx++;
// 	}
// 	return (1);
// }

int get_matrix(t_hooks *hooks, char *file, t_grid *grid)
{
    int		fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
	grid->width_grid = 0;
    if (read_fdf(fd, hooks, grid) == 0)
        return (0);
    return (1);
}
