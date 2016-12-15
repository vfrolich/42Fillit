/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opencompare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:05:05 by arosset           #+#    #+#             */
/*   Updated: 2016/12/09 18:09:28 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_open_extern(void)
{
	char	buf[700];
	char	*str;
	int		fd;
	int		ret;

	fd = open("extern_file.txt", O_RDWR);
	if (fd != -1)
	{
		ret = read(fd, buf, 700);
		if (ret != -1 && ft_strlen(buf) <= 545)
		{
			buf[ft_strlen(buf)] = '\0';
			str = ft_strnew(ft_strlen(buf));
			str = ft_strcpy(str, buf);
			close(fd);
			return (str);
		}
		ft_putendl_fd("error", 1);
		return (0);
	}
	ft_putendl_fd("error", 1);
	return (0);
}

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

t_lst	*ft_reset_lst(t_lst *lst)
{
	while (lst->prev != NULL)
	{
		lst->use = 0;
		lst = lst->prev;
	}
	return (lst);
}
