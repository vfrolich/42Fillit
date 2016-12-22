/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:50:44 by arosset           #+#    #+#             */
/*   Updated: 2016/12/21 19:17:04 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_create_tab(int i)
{
	char	**tab;
	int		j;
	int		k;
	int		line;

	j = 0;
	k = 0;
	line = -1;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	while (line++ < i)
		tab[line] = ft_strnew(i);
	tab[i] = NULL;
	while (j < i)
	{
		k = 0;
		while (k < i)
		{
			if (tab[j][k] != '.')
				tab[j][k] = '.';
			k++;
		}
		j++;
	}
	return (tab);
}

int		ft_check_pos(char **grid, char **tetri, int y, int x)
{
	int i;
	int j;
	int count_c;

	count_c = 0;
	i = 0;
	while (tetri[i] && i + y < (int)ft_strlen(grid[0]))
	{
		j = 0;
		while (tetri[i][j] && j + x < (int)ft_strlen(grid[0]))
		{
			if (ft_isalpha(tetri[i][j]) == 1 && grid[i + y][j + x] != '.')
				return (-1);
			if (ft_isalpha(tetri[i][j]) == 1 && grid[i + y][j + x] == '.')
				count_c++;
			if (count_c == 4)
				return (0);
			j++;
		}
		i++;
	}
	if (i + y >= (int)ft_strlen(grid[0]) || j + x >= (int)ft_strlen(grid[0]))
		return (-1);
	return (0);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
