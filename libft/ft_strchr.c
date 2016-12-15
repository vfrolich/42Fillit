/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:23:23 by arosset           #+#    #+#             */
/*   Updated: 2016/11/16 11:41:29 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
