/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:48:14 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 22:08:17 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header_bonus.h"

void	check_validity(t_hooks *hooks, char **arr, int i)
{
	if (!char_is_degits(&arr[i][0]))
	{
		ft_printf("Error: Invalid syntax, line %d, col %d\n",
			hooks->height_grid + 1,
			i + 1);
		exit(1);
	}
	if (is_overflowed_int(arr[i]))
	{
		ft_printf("Error: Found an overflow, line: %d, col %d\n",
			hooks->height_grid + 1,
			i + 1);
		exit(1);
	}
}

int	cols_count(char **arr, t_hooks *hooks)
{
	int	i;
	int	z_value;

	i = 0;
	while (arr[i])
	{
		check_validity(hooks, arr, i);
		z_value = ft_atoi(arr[i]);
		if (hooks->height_grid == 0 && i == 0)
		{
			hooks->z_min = z_value;
			hooks->z_max = z_value;
		}
		else
		{
			if (z_value > hooks->z_max)
				hooks->z_max = z_value;
			if (z_value < hooks->z_min)
				hooks->z_min = z_value;
		}
		i++;
	}
	return (i);
}

int	atoi_base(char *str, int base)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (base == 16 && str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i])
	{
		if (base == 16 && str[i] >= 'A' && str[i] <= 'F')
			nbr = nbr * base + (str[i] - 'A' + 10);
		else if (base == 16 && str[i] >= 'a' && str[i] <= 'f')
			nbr = nbr * base + (str[i] - 'a' + 10);
		else
			nbr = nbr * base + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	valid_extention(char *name)
{
	char	*extention;

	extention = ft_strrchr(name, '.');
	if (!extention)
		print_error("No extention found\n", 1);
	return (ft_strncmp(extention, ".fdf", 4) == 0);
}

int	get_z(char *str, t_hooks *hooks)
{
	return (ft_atoi(str) * hooks->z_factor * hooks->scale);
}
