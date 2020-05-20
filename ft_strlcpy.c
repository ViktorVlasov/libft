/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:27:30 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/20 12:31:59 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t size;

	if (!dst || !src)
		return (0);
	size = dstsize;
	i = 0;
	while (src[i] != '\0' && size > 0)
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	else if (dstsize > 0)
		dst[i - 1] = '\0';
	return (ft_strlen(src));
}
