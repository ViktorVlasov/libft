/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:02:42 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/12 14:22:37 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <malloc.h>

void	*ft_calloc(size_t num, size_t size)
{
	void			*arr;
	unsigned char	*tmp;

	if (size != 0 && (((num * size) / size) != num))
		return (NULL);
	arr = malloc(size * num);
	if (arr == NULL)
		return (NULL);
	tmp = (unsigned char*)arr;
	size *= num;
	while (size > 0)
	{
		*tmp = '\0';
		tmp++;
		size--;
	}
	return (arr);
}
