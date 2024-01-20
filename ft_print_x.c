#include "ft_printf.h"

int	ft_print_x(unsigned int n, int letter_case)
{
	char *system;

	if (letter_case == 'x')
		system = "0123456789abcdef";
	else if (letter_case == 'X')
		system = "0123456789ABCDEF";
	return (ft_hexadec_nbr(n, system));
}