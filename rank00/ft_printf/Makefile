NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

SRCS_FILES  = ft_printf.c ft_utils.c ft_convert_cs.c \
              ft_print_numbers.c ft_print_p.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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
