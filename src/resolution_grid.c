/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:13:16 by vfrolich          #+#    #+#             */
/*   Updated: 2016/12/15 15:53:41 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetri_to_tab(char **grid, char **tetri, int y, int x)
{
	int i;
	int j;
	int len;
	
	len = ft_strlen(grid[0]);
	i = 0;
	while (tetri[i] && i + y < len)
	{
		j = 0;
		while (tetri[i][j] && j + x < len)
		{
			if (grid[i + y][j + x] == '.' && ft_isalpha(tetri[i][j]) == 1)
					grid[i + y][j + x] = tetri[i][j];
			j++;
		}
		i++;
	}
	return (grid);
}

int	ft_check_resolution(char **grid, t_lst *lst, int y, int x)
{
	int len;


	len = ft_strlen(grid[0]);
	if (ft_check_pos(grid, lst->tetri, y , x) == -1)
	{
		if (x < len)
			return (ft_check_resolution(grid, lst, y , x + 1));
		if (y < len)
			return (ft_check_resolution(grid, lst, y + 1, 0));
	}
	if (ft_check_pos(grid, lst->tetri, y , x) == 0 && !lst->use)	
		return (1);
	else 
		return (0);
}

int 	ft_back(char ***grid, t_lst *lst, int y, int x)
{
	if (ft_check_resolution(*grid, lst, y , x))
		{
			*grid = ft_resolution(*grid, lst, y ,x);
			if (!lst->next || ft_back(grid, lst->next, 0 ,0))
				return (1);
			else
			{
				*grid = ft_del_tetri(*grid, lst);
				if (x + 1 < (int)ft_strlen(*grid[0]))
					x++;
				else
				{
					x = 0;
					y++;
				}
				ft_back(grid, lst, y ,x);
				if (ft_lst_used(ft_lststart(lst)))
					return (1);
			}
		}	
	return (0);
}

void	ft_main_resolution(t_lst *lst, int i)
{
	int 	x;
	int 	y;
	char 	**grid;

	y = 0;
	x = 0;
	grid = ft_create_tab(i);
	if (ft_back(&grid, lst, y ,x))
		ft_print_tab(grid);
	else
		ft_main_resolution(ft_reset_lst(lst), i + 1);
}

