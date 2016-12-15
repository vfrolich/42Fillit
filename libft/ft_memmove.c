/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:19:27 by arosset           #+#    #+#             */
/*   Updated: 2016/11/10 10:43:15 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_src = (unsigned char *)src;
	t_dst = (unsigned char *)dst;
	i = 0;
	if (t_src == t_dst)
		return (dst);
	if (t_src < t_dst)
	{
		while (len--)
			t_dst[len] = t_src[len];
		return (dst);
	}
	else
	{
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
		return (dst);
	}
}
