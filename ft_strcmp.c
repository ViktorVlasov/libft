/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:03:35 by efumiko           #+#    #+#             */
/*   Updated: 2020/12/04 20:03:38 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((*ss1 != '\0' || *ss2 != '\0'))
	{
		if (*ss1 > *ss2)
			return (*ss1 - *ss2);
		if (*ss2 > *ss1)
			return (*ss1 - *ss2);
		ss2++;
		ss1++;
	}
	return (0);
}