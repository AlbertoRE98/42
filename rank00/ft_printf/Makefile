NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -Iincludes
AR          = ar rcs
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

SRCS_FILES  = ft_printf.c ft_utils.c ft_convert_cs.c \
              ft_print_numbers.c ft_print_p.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Librería $(NAME) creada con éxito."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "Objetos eliminados."

fclean: clean
	$(RM) $(NAME)
	@echo "Librería y objetos eliminados."

re: fclean all

.PHONY: all clean fclean re
