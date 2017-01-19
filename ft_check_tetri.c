/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:38:30 by arosset           #+#    #+#             */
/*   Updated: 2017/01/19 13:01:18 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_empty(char **tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_move_top(char **tetri)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (tetri[j][i] == '#')
			return (tetri);
		i++;
	}
	tmp = tetri[j];
	while (j < 3)
	{
		tetri[j] = tetri[j + 1];
		j++;
	}
	tetri[j] = tmp;
	return (ft_move_top(tetri));
}

char	**ft_move_left(char **tetri)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	if (ft_good_place(tetri) == 1)
		return (tetri);
	j = 0;
	while (j < 4)
	{
		i = 0;
		tmp = tetri[j][i];
		while (i < 3)
		{
			tetri[j][i] = tetri[j][i + 1];
			i++;
		}
		tetri[j][i] = tmp;
		j++;
	}
	return (ft_move_left(tetri));
}

int		ft_main_check(t_lst *lst)
{
	while (lst)
	{
		if (!ft_check_shape(lst->tetri) || !ft_check_empty(lst->tetri))
			return (-1);
		lst->tetri = ft_move_top(lst->tetri);
		lst->tetri = ft_move_left(lst->tetri);
		lst = lst->next;
	}
	return (0);
}
