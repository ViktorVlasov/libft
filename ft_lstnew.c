/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:12:27 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/21 23:15:17 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
