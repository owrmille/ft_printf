#include "ft_printf.h"

int	ft_check_type(char type, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (type == 'c')
		printed_chars += ft_print_c(va_arg(args, int));
	else if (type == 's')
		printed_chars += ft_print_s(va_arg(args, char *));
	else if (type == 'd')
		printed_chars += ft_print_d(va_arg(args, int));
	return (printed_chars);
}
