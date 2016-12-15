/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:38:30 by arosset           #+#    #+#             */
/*   Updated: 2016/12/07 18:43:18 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
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

int		ft_tetri_comp(char **tetri, t_lst *ref)
{
	int j;

	if (ft_check_empty(tetri) == -1)
	{
		ft_putendl("empty");
		return (-1);
	}
	tetri = ft_move_top(tetri);
	tetri = ft_move_left(tetri);
	while (ref)
	{
		j = 0;
		while (j < 4 && ft_strcmp(tetri[j], ref->tetri[j]) == 0)
			j++;
		if (j == 4)
			return (0);
		ref = ref->next;
	}
	return (-1);
}

int		ft_main_check(t_lst *lst)
{
	char	*str;
	t_lst	*ref;

	str = ft_open_extern();
	ref = ft_mainlst(str);

	while (lst)
	{
		if (ft_tetri_comp(lst->tetri, ref) == -1)
			return (-1);
		lst = lst->next;
	}
	return (0);
}
