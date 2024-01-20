#include "ft_printf.h"

int	ft_printf(char *content_str, ...)
{
	int		printed_chars;
	int		i;
	va_list	args;

	printed_chars = 0;
	i = 0;
	va_start(args, content_str);
	while (content_str[i])
	{
		if (content_str[i] == '%')
			printed_chars += check_type(content_str[++i], args);
		else
			printed_chars += ft_print_c(content_str[i++]);
	}
	va_end(args);
	// if (printed_chars < 0)
	// 	return (-1);
	return (printed_chars);
}
