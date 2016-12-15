/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:03:27 by arosset           #+#    #+#             */
/*   Updated: 2016/12/15 19:07:23 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_acquisition(char *argv)
{
	char	buf[700];
	char	*str;
	int		fd;
	int		ret;

	fd = open(argv, O_RDWR);
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

int		ft_usage(int c)
{
	if (c == 1)
	{
		ft_putendl_fd("usage: ./fillit target_file", 1);
		return (0);
	}
	if (c == 2)
	{
		ft_putendl_fd("error", 1);
		return (0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;
	t_lst	*lst;
	int		i;

	i = 2;
	if (argc != 2)
		return (ft_usage(1));
	if (argc == 2)
	{
		str = ft_acquisition(argv[1]);
		if (str == NULL)
			return (0);
		if (ft_check_error(str) == -1)
			return (ft_usage(2));
		lst = ft_mainlst(str);
		if (ft_main_check(lst) == -1)
			return (ft_usage(2));
		ft_transform(lst);
		ft_main_resolution(lst, i);
	}
	return (0);
}
