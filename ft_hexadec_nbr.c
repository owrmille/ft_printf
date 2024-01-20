#include "ft_printf.h"

int	ft_hexadec_nbr(unsigned long n, char *system)
{
	int	printed_chars;

	printed_chars = 0;
	if (n > 15)
	{
		printed_chars += ft_hexadec_nbr(n / 16, system);
		printed_chars += ft_hexadec_nbr(n % 16, system);
	}
	else
		printed_chars += ft_print_c(system[n]);
	return (printed_chars);
}