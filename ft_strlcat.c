/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:25:53 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/20 16:23:38 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	res;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
	{
		res = ft_strlen(dst) + ft_strlen(src);
		i = ft_strlen(dst);
		j = 0;
		while (i < dstsize - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (res);
}
