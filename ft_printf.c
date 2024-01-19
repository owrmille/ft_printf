#include "ft_printf.h"

int	ft_printf(void)
{
	char	*format_str = "Hello my name is %s %c and I'm %d years old";
	char	*arg1 = "Laura";
	char	arg2 = 'M';
	int		arg3 = 23;
	int		i;

	i = 0;
	while (format_str[i])
	{
		while (format_str[i] != '%')
		{
			ft_putchar_fd(format_str[i], 1);
			i++;
		}
		if (format_str[i + 1] == 's')
			ft_putstr_fd(arg1, 1);
		else if (format_str[i + 1] == 'c')
			ft_putchr_fd(arg2, 1);
		else if (format_str[i + 1] == 'd')
			ft_putnbr_fd(arg3, 1);
	}
	return (0);
}
