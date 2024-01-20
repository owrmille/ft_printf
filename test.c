#include "ft_printf.h"
# include <stdio.h>

// to compile and run:
// 1. make
// 2. cc -Wall -Wextra -Werror -o test test.c -L. -lftprintf
// (where test.c can be any file with tests)

int test_c()
{
	char	*content = "My grade is %c|";
	char	value = 'D';

	printf("\nOriginal result:\n");
	printf("\nLength of string: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_s()
{
	char	*content = "Hello my name is %s|";
	char	*value = "Laura";

	printf("\nOriginal result:\n");
	printf("\nLength of string: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_d()
{
	char	*content = "I'm %d years old|";
	int		value = 23;
	
	printf("\nOriginal result:\n");
	printf("\nLength of string: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_all()
{
	char	*content = "Hello my name is %s %c and I'm %d years old|";
	char	character = 'D';
	char	*str = "Laura";
	int		digit = 23;

	printf("\nOriginal result:\n");
	printf("\nLength of string: %d\n", printf(content, str, character, digit));
	printf("\nMy result:\n");
	return (ft_printf(content, str, character, digit));
}

int test_c_error()
{
	char	*content = "My grade is %c|";
	char *value = "OOPS";

	printf("\nOriginal result:\n");
	printf("\nLength of string: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int	main(void)
{
	char option = 'A';
	int error_flg = 0;

	if (option == 'c' &&!error_flg)
		printf("\nNumber of printed characters: %d\n", test_c());
	else if (option == 'd' &&!error_flg)
		printf("\nNumber of printed characters: %d\n", test_d());
	else if (option == 's' &&!error_flg)
		printf("\nNumber of printed characters: %d\n", test_s());
	else if (option == 'A' &&!error_flg)
		printf("\nNumber of printed characters: %d\n", test_all());

	// errors: (can't get an error, don't know why)
	else if (option == 'c' && error_flg)
		printf("\nNumber of printed characters: %d\n", test_c_error());

	return (0);
}
