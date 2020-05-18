/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:03:01 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/18 18:47:32 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char*)dst;
	from = (unsigned char*)src;
	while (n > 0)
	{
		*to = *from;
		if (*to == (unsigned char)c)
		{
			to++;
			break ;
		}
		++to;
		++from;
		--n;
	}
	if (n == 0 && *to != c)
		return (NULL);
	return (to);
}
