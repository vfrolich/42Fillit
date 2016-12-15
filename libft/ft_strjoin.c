/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:48:52 by arosset           #+#    #+#             */
/*   Updated: 2016/11/11 15:04:23 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
