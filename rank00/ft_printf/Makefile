NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS =	ft_printf.c \
		ft_utils.c \
		ft_convert_cs.c \
        ft_print_numbers.c \
		ft_print_p.c
OBJS = $(SRCS: .c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
%.o: %.c
		$(CC) $(CFLAGS) -c $, -o $@
clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY all clean fclean re
