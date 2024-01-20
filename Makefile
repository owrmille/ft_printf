NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MAKE_LIB = ar -rcs
INCS = .

SRCS =	ft_printf.c \
		ft_check_type.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_d.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(MAKE_LIB) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(INCS)

$(LIBFT) :
	cd $(LIBFT_PATH) && make
	cp $(LIBFT) $(NAME)

clean :
	rm -rf $(OBJS) $(NAME)

fclean : clean
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all bonus clean fclean re