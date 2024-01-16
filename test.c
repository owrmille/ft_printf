#include "ft_printf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (ft_strchr("1\0", '1'))
			printf("It works.");
		else
			printf("It doesn't work.");
	}
	return (0);
}
