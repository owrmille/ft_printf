#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(char *content_str, ...);
int	ft_check_type(char type, va_list args);

#endif