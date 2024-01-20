#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int i;
	int printed_chars;
	int null_len;

	i = 0;
	printed_chars = 0;
	if (!s)
	{
		null_len = ft_strlen("(null)");
		write(1, "(null)", null_len);
		return (null_len);
	}
	while (s[i] != '\0')
		printed_chars += write(1, &s[i++], 1);
	return (printed_chars);
}
