/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:59:15 by vfrolich          #+#    #+#             */
/*   Updated: 2016/12/07 15:24:31 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetri(char **raw_tetri)
{
	int i;

	i = 0;
	while (raw_tetri[i] != NULL)
		i++;
	return (i / 4);
}

void	ft_lst_fill(char **raw_tetri, t_lst *lst, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (raw_tetri[i])
	{
		lst->tetri[j] = raw_tetri[i];
		i++;
		j++;
		if ((i % 4) == 0)
		{
			lst->letter = c;
			lst->use = 0;
			lst = lst->next;
			j = 0;
			c++;
		}
	}
}

t_lst	*ft_lstcreate_one(void)
{
	t_lst	*new;
	int		i;

	i = 0;
	new = (t_lst *)malloc(sizeof(t_lst));
	new->tetri = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		new->tetri[i] = (char *)malloc(sizeof(char) * 5);
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_lst	*ft_lstcreate(char **raw_tetri)
{
	int		size;
	t_lst	*start;
	t_lst	*new;
	t_lst	*tmp;

	size = ft_count_tetri(raw_tetri);
	start = ft_lstcreate_one();
	start->prev = NULL;
	if (size > 1)
	{
		new = ft_lstcreate_one();
		start->next = new;
		new->next = NULL;
		new->prev = start;
	}
	while (size > 2)
	{
		tmp = ft_lstcreate_one();
		tmp->prev = new;
		new->next = tmp;
		size--;
		new = new->next;
	}
	return (start);
}

t_lst	*ft_mainlst(char *str)
{
	char	**tetris;
	int		count;
	t_lst	*lst;
	char	c;

	c = 'A';
	count = 0;
	tetris = ft_strsplit(str, '\n');
	count = ft_count_tetri(tetris);
	lst = ft_lstcreate(tetris);
	ft_lst_fill(tetris, lst, c);
	return (lst);
}
