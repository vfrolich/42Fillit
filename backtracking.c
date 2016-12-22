/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:55:28 by vfrolich          #+#    #+#             */
/*   Updated: 2016/12/22 12:44:45 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_del_tetri(char **grid, t_lst *lst)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == lst->letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
	lst->use = 0;
	return (grid);
}

t_lst	*ft_lststart(t_lst *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

int		ft_lst_used(t_lst *lst)
{
	lst = ft_lststart(lst);
	while (lst)
	{
		if (!lst->use)
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	**ft_resolution(char **grid, t_lst *lst, int y, int x)
{
	int len;

	len = ft_strlen(grid[0]);
	if (ft_check_pos(grid, lst->tetri, y, x) == -1)
	{
		if (x < len)
			return (ft_resolution(grid, lst, y, x + 1));
		if (y < len)
			return (ft_resolution(grid, lst, y + 1, 0));
	}
	grid = ft_tetri_to_tab(grid, lst->tetri, y, x);
	lst->use = 1;
	return (grid);
}

int		ft_resolv_pos(char **grid, int *y, int *x)
{
	int len;

	len = (int)ft_strlen(grid[0]);
	if (*x + 1 <= len)
		(*x)++;
	while (*y < len)
	{
		if (*x == len)
			*x = 0;
		while (*x < len)
		{
			if (!ft_isalpha(grid[*y][*y]))
				return (0);
			*x = *x + 1;
		}
		*y = *y + 1;
	}
	return (0);
}
