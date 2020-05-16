/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:03:59 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/12 14:31:55 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <io.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		_write(fd, s, 1);
		s++;
	}
}