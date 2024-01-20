#include "ft_printf.h"
# include <stdio.h>
// to compile and run:
// 1. make
// 2. cc -Wall -Wextra -Werror -o test test.c -L. -lftprintf
// (where test.c can be any file with tests)

int	main(void)
{
	char	*content_str = "Hello my name is %s %c and I'm %d years old";
	char	*str = "Laura";
	char	character = 'M';
	int		digit = 23;
	ft_printf(content_str, str, character, digit);
	return (0);
}
