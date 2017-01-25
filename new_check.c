/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:57:56 by vfrolich          #+#    #+#             */
/*   Updated: 2017/01/25 18:29:43 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_cross_check(char **tetri, int i, int j)
{
	int		count;

	count = 0;
	if (i < 3)
		if (tetri[i + 1][j] == '#')
			count++;
	if (j < 3)
		if (tetri[i][j + 1] == '#')
			count++;
	if (i > 0)
		if (tetri[i - 1][j] == '#')
			count++;
	if (j > 0)
		if (tetri[i][j - 1] == '#')
			count++;
	return (count);
}

int		ft_is_square(char **tetri)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (tetri[++i])
	{
		j = -1;
		while (tetri[i][++j])
		{
			if (tetri[i][j] == '#')
			{
				if (ft_cross_check(tetri, i, j) != 2)
					return (0);
				count = count + ft_cross_check(tetri, i, j);
			}
		}
	}
	if (count == 8)
		return (1);
	else
		return (0);
}

int		ft_check_shape(char **tetri)
{
	int count;
	int count_t;
	int i;
	int j;

	i = -1;
	count = 0;
	count_t = 0;
	while (tetri[++i])
	{
		j = -1;
		while (tetri[i][++j])
		{
			if (tetri[i][j] == '#')
			{
				count_t++;
				count = count + ft_cross_check(tetri, i, j);
			}
		}
	}
	if ((count == 6 && count_t == 4) || ft_is_square(tetri))
		return (1);
	else
		return (0);
}
