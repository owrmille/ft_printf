#include "ft_printf.h"

int	ft_print_p(unsigned long ptr_adress)
{
	int		printed_chars;
	char	*system;

	printed_chars = 0;
	printed_chars += ft_print_s("0x");
	system = "0123456789abcdef";
	printed_chars += ft_hexadec_nbr(ptr_adress, system);
	return (printed_chars);
}