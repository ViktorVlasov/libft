/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:01:24 by efumiko           #+#    #+#             */
/*   Updated: 2020/05/16 14:02:11 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

static char	*strfromchar(char dest[], char c)
{
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}

static int	get_count_strings(char *str, char c)
{
	int	count_strings;
	int	i;

	i = 0;
	count_strings = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			++count_strings;
		++i;
	}
	count_strings += 1;
	return (count_strings);
}

static char	**get_memarr(char **result, char *strclear, char c)
{
	int	i;
	int	count_symb;
	int	num_str;

	i = 0;
	count_symb = 0;
	num_str = 0;
	while (strclear[i] != '\0')
	{
		count_symb = 0;
		while (strclear[i] != c && strclear[i] != '\0')
		{
			count_symb++;
			i++;
		}
		result[num_str] = (char*)malloc((count_symb + 1) * sizeof(char));
		num_str++;
		if (strclear[i] == c)
			i++;
	}
	return (result);
}

static char	**fill_arr(char **result, char *strclear, char c)
{
	int	i;
	int	indx_str;
	int	num_str;

	i = 0;
	indx_str = 0;
	num_str = 0;
	while (strclear[i] != '\0')
	{
		while (strclear[i] != c && strclear[i] != '\0')
		{
			result[num_str][indx_str] = strclear[i];
			i++;
			indx_str++;
		}
		result[num_str][indx_str] = '\0';
		num_str++;
		if (strclear[i] == c)
			i++;
		indx_str = 0;
	}
	return (result);
}

char		**ft_split(char const *s, char c)
{
	char	chr[2];
	char	*strclear;
	int		count_strings;
	char	**result;

	strclear = ft_strtrim(s, strfromchar(chr, c));
	count_strings = get_count_strings(strclear, c);
	result = (char**)malloc(count_strings * sizeof(char*));
	if (result == NULL)
		return (NULL);
	get_memarr(result, strclear, c);
	fill_arr(result, strclear, c);
	return (result);
}
