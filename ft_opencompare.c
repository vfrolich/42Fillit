/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opencompare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:05:05 by arosset           #+#    #+#             */
/*   Updated: 2017/01/19 13:02:22 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_transform(t_lst *lst)
{
	int		i;
	int		j;
	char	**tab;

	while (lst)
	{
		i = 0;
		j = 0;
		tab = lst->tetri;
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] == '#')
					tab[i][j] = lst->letter;
				j++;
			}
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int		ft_good_place(char **tetri)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tetri[j][0] == '#')
			return (1);
		j++;
	}
	return (0);
}
