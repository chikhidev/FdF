/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:33:32 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 15:58:32 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header_bonus.h"

void	fill_alphabet(t_alphabet *reps, char *content, int code)
{
	reps->content = content;
	reps->code = code;
}

void	helper(t_alphabet reps[27], int i)
{
	fill_alphabet(&reps[i++], ft_strdup("v"), 9);
	fill_alphabet(&reps[i++], ft_strdup("w"), 13);
	fill_alphabet(&reps[i++], ft_strdup("x"), 7);
	fill_alphabet(&reps[i++], ft_strdup("y"), 16);
	fill_alphabet(&reps[i++], ft_strdup("z"), 6);
}

void	initialize_alphabet(t_alphabet reps[27])
{
	int	i;

	i = 0;
	fill_alphabet(&reps[i++], ft_strdup("a"), 0);
	fill_alphabet(&reps[i++], ft_strdup("b"), 11);
	fill_alphabet(&reps[i++], ft_strdup("c"), 8);
	fill_alphabet(&reps[i++], ft_strdup("d"), 2);
	fill_alphabet(&reps[i++], ft_strdup("e"), 14);
	fill_alphabet(&reps[i++], ft_strdup("f"), 3);
	fill_alphabet(&reps[i++], ft_strdup("g"), 5);
	fill_alphabet(&reps[i++], ft_strdup("h"), 4);
	fill_alphabet(&reps[i++], ft_strdup("i"), 34);
	fill_alphabet(&reps[i++], ft_strdup("j"), 38);
	fill_alphabet(&reps[i++], ft_strdup("k"), 40);
	fill_alphabet(&reps[i++], ft_strdup("l"), 37);
	fill_alphabet(&reps[i++], ft_strdup("m"), 46);
	fill_alphabet(&reps[i++], ft_strdup("n"), 45);
	fill_alphabet(&reps[i++], ft_strdup("o"), 31);
	fill_alphabet(&reps[i++], ft_strdup("p"), 35);
	fill_alphabet(&reps[i++], ft_strdup("q"), 12);
	fill_alphabet(&reps[i++], ft_strdup("r"), 15);
	fill_alphabet(&reps[i++], ft_strdup("s"), 1);
	fill_alphabet(&reps[i++], ft_strdup("t"), 17);
	fill_alphabet(&reps[i++], ft_strdup("u"), 32);
	helper(reps, i);
}

char	*get_char(int keycode)
{
	t_alphabet	reps[26];
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	initialize_alphabet(reps);
	while (i < 26)
	{
		if (reps[i].code == keycode)
			tmp = reps[i].content;
		else
			free(reps[i].content);
		i++;
	}
	return (tmp);
}
