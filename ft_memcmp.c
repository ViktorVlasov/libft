/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:03:34 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/12 14:55:23 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;

	str1 = s1;
	str2 = s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((int)(str1 - str2));
		++str1;
		++str2;
		--n;
	}
	return (0);
}
