/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:29:57 by arosset           #+#    #+#             */
/*   Updated: 2016/11/14 14:50:30 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;
	int delim;

	if (s != NULL)
	{
		delim = ft_strlen(s);
		i = 0;
		while (i < delim)
		{
			ft_putnbr(i);
			s[i] = '\0';
			i++;
		}
	}
}
