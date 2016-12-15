/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:24:38 by arosset           #+#    #+#             */
/*   Updated: 2016/12/06 13:02:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *str)
{
	int		i;
	int		count;
	int		countd;

	count = 0;
	countd = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '.')
			count = 1;
		if (str[i] == '#')
			countd = 1;
		i++;
	}
	if (count == 0 || countd == 0)
		return (-1);
	return (1);
}

int		ft_check_format(char *str)
{
	int		i;
	int		start;
	int		count;

	i = 1;
	start = -1;
	count = 0;
	while (str[i + start])
	{
		if (count == 4)
		{
			start += 1;
			count = 0;
		}
		if (!(i % 5) && str[i + start] == '\n')
			count++;
		if (!(i % 5) && str[i + start] != '\n')
			break ;
		if (count != 4 && str[i + start] == '\n' && str[i + start + 1] == '\n')
			break ;
		i++;
	}
	if (!str[i + start] && count == 4)
		return (1);
	return (-1);
}

int		ft_check_error(char *str)
{
	if (ft_check_char(str) == -1)
		return (-1);
	if (ft_check_format(str) == -1)
		return (-1);
	else
		return (1);
}
