#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int i;
	int printed_chars;

	i = 0;
	printed_chars = 0;
	while (s[i] != '\0')
	{
		printed_chars += write(1, &s[i++], 1);
	}
	return (printed_chars);
}
