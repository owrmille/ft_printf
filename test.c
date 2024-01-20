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
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_s()
{
	char	*content = "Hello my name is %s|";
	// char	*value = "Laura";
	char *value = NULL;

	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_d()
{
	char	*content = "I'm %d years old|";
	int		value = 23;
	
	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_x()
{
	char	*content = "Just a test for x: %x|";
	unsigned long		value = 24096;
	
	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_X()
{
	char	*content = "Just a test for X: %X|";
	unsigned long value = 24096;
	
	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_p()
{
	
	char	*content = "Just a test for p: %p|";
	// int num = 42;
	// int *value = &num;

	int *value = NULL;
	
	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int test_percent_sign()
{
	char	*content = "The rate was 50%%|";
	char		value = '%';
	
	printf("\nOriginal result:\n");
	printf("\nNumber of printed characters: %d\n", printf(content, value));
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
	printf("\nNumber of printed characters: %d\n", printf(content, str, character, digit));
	printf("\nMy result:\n");
	return (ft_printf(content, str, character, digit));
}

int test_c_error()
{
	char	*content = "My grade is %c|";
	char *value = "OOPS";

	printf("\nOriginal result:\n");
	printf("\nLNumber of printed characters: %d\n", printf(content, value));
	printf("\nMy result:\n");
	return (ft_printf(content, value));
}

int	test_hexadec_nbr()
{
	// unsigned long n = 255; // ff
	unsigned long n = 24096; // 5E20
	char *system = "0123456789abcdef";
	return (ft_hexadec_nbr(n, system));
}

int	main(void)
{
	char option = 'p';
	int hex_flg = 0;
	int error_flg = 0;

	if (hex_flg)
	{
		printf("Hex. number:\n");
		printf("\nNumber of printed characters: %d\n", test_hexadec_nbr());
	}
	else if (option == 'c' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_c());
	else if ((option == 'd') || (option == 'i'))
		printf("\nNumber of printed characters: %d\n", test_d());
	else if (option == 's' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_s());
	else if (option == 'x' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_x());
	else if (option == 'X' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_X());
	else if (option == 'p' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_p());
	else if (option == 'A' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_all());
	else if (option == '%' && (!error_flg))
		printf("\nNumber of printed characters: %d\n", test_percent_sign());

	// errors: (can't get an error, don't know why)
	else if (option == 'c' && error_flg)
		printf("\nNumber of printed characters: %d\n", test_c_error());

	return (0);
}
