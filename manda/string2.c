/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:59:20 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/25 15:57:40 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int	is_overflowed_int(char *str)
{
	int		res;
	char	*num;
	int		i;

	i = 0;
	res = ft_atoi(str);
	num = ft_itoa(res);
	if (str[0] == '+')
		i++;
	while (str[i] && str[i] != ',')
	{
		if (str[i] != num[i])
		{
			free(num);
			return (1);
		}
		i++;
	}
	free(num);
	return (0);
}

int	char_is_degits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
