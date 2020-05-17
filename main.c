#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "stdio.h"

static void		ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(memcmp("salut", "salut", 5));
	// else if (arg == 2)
	// 	ft_print_result(memcmp("t\200", "t\0", 2));
	// else if (arg == 3)
	// 	ft_print_result(memcmp("testss", "test", 5));
	// else if (arg == 4)
	// 	ft_print_result(memcmp("test", "tEst", 4));
	// else if (arg == 5)
	// 	ft_print_result(memcmp("", "test", 4));
	// else if (arg == 6)
	// 	ft_print_result(memcmp("test", "", 4));
	// else if (arg == 7)
	// 	ft_print_result(memcmp("abcdefghij", "abcdefgxyz", 7));
	else if (arg == 8)
		ft_print_result(memcmp("abcdefgh", "abcdwxyz", 6));
	printf("\n");
	if (arg == 9)
		ft_print_result(ft_memcmp("abcdefgh", "abcdwxyz", 6));
	printf("\n");
	return (0);
}
