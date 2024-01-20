#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *content_str, ...);
int	ft_check_type(char type, va_list args);
int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_d(int n);

#endif