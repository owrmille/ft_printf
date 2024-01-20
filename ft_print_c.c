#include "ft_printf.h"

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}
