FILES = ft_printf \
		test

LIBFT = ./libft/libft.a
MAKE_LIB = ar -rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLS = ft_printf.h
HEADERS = $(INCLS)
CFILES =  $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))
NAME = libftprintf.a
$(NAME): $(OFILES) $(LIBFT)
	$(MAKE_LIB) $(NAME) $(OFILES)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(NAME) $(OFILES)
all: $(NAME)
clean:
		rm -f *.o
flcean:
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re