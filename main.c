#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "stdio.h"

char *
	strnstr(s, find, slen)
		const char *s;
const char *find;
size_t slen;
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0')
	{
		len = strlen(find);
		do
		{
			do
			{
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int strncmp(const char *s1, const char *s2, size_t n)
{

	if (n == 0)
		return (0);
	do
	{
		if (*s1 != *s2++)
			return (*(const unsigned char *)s1 -
					*(const unsigned char *)(s2 - 1));
		if (*s1++ == '\0')
			break;
	} while (--n != 0);
	return (0);
}

static void ft_freeresult(char ***result)
{
	int i;

	i = 0;
	while ((*result)[i])
		free((*result)[i++]);
	free(*result);
}

static int ft_token_count(char const *str, char c)
{
	int tok;
	int i;

	if (c == '\0')
		return (1);
	tok = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && i > 0 && str[i - 1] != c)
			tok++;
		i++;
	}
	if (i > 0 && !str[i] && str[i - 1] != c)
		tok++;
	return (tok);
}

static void ft_split_tokens(char *scopy, char c, char ***result)
{
	int i;
	int tok;
	int end;
	int i_next;

	i_next = 0;
	i = 0;
	tok = 0;
	while (scopy[i])
	{
		end = i + 1;
		while (scopy[end] != c && scopy[end] != '\0')
			end++;
		i_next = scopy[end] > 0 ? (end + 1) : end;
		scopy[end] = '\0';
		if (!((*result)[tok++] = ft_strdup(&scopy[i])))
		{
			ft_freeresult(result);
			return;
		}
		while (c != '\0' && scopy[i_next] == c)
			i_next++;
		i = i_next;
	}
}

/*
** Splits ’s’ using the character ’c’ as a delimiter.
** Allocates and returns an array of strings obtained.
*/

char **ft_spli(char const *s, char c)
{
	char *scopy;
	char **result;
	int counttok;
	char set[2];

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	scopy = ft_strtrim(s, set);
	counttok = ft_token_count(s, c);
	if (!(result = (char **)malloc((counttok + 1) * sizeof(char *))))
		return (NULL);
	result[counttok] = NULL;
	ft_split_tokens(scopy, c, &result);
	free((void *)scopy);
	return (result);
}

int main()
{
	// // FT_STRNSTR
	// // check len == 0 || 1
	// char *str = "Bare Baz";
	// char *to = "Baz";
	// // char *to = “Ba”;
	// // char *to = “B”;
	// int len = 8;
	// printf("my:\n\t%s\n", ft_strnstr(str, to, len));
	// printf("std:\n\t%s\n", strnstr(str, to, len));
	// ft_strtrim("123456", "0");

	// char *s = "split this \0for me !_";

	// char **result = ft_split(s, '\0');
	// int i = 0;
	// while (result[i])
	// {
	// 	printf("%s\n", result[i]);
	// 	i++;
	// }

	// const char *largestring = "Foo Bar Baz";
	// const char *smallstring = "Bar";
	// char *ptr;

	// ptr = ft_strnstr(largestring, smallstring, 0);
	// printf("%s", ptr);

	//const char *s = "substrd12345";
	//printf("%s", ft_substr(s, 4, -23));

	// printf("M:%d\n", ft_atoi("-0000000000002147483648"));
	// printf("O:%d\n", atoi("-0000000000002147483648"));

	// printf("M:%d\n", ft_atoi("0000000000002147483647"));
	// printf("O:%d\n", atoi("0000000000002147483647"));

	// printf("M:%d\n", ft_atoi("0000000000002147483648"));
	// printf("O:%d\n", atoi("0000000000002147483648"));

	// printf("M:%d\n", ft_atoi("-2999999999812345436345132135344"));
	// printf("O:%d\n", atoi("-2999999999812345436345132135344"));

	// printf("M:%d\n", ft_atoi("2999999999812345436345132135344"));
	// printf("O:%d\n", atoi("2999999999812345436345132135344"));

	//printf("M:%d\n", ft_atoi("-29999999998"));
	//printf("O:%d\n", atoi("-29999999998"));

	return (0);
}
