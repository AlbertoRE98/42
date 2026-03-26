NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

# Source Directories Divided by categories
CONV_DIR = src/conversion_and_utils
IS_DIR = src/ft_is
PUT_DIR = src/ft_put
MEM_DIR = src/ft_mem
STR_DIR = src/ft_str
LISTS_DIR = src/ft_lists

# Source files 
CONV_SRCS = $(CONV_DIR)/ft_atoi.c \
            $(CONV_DIR)/ft_atoll.c \
            $(CONV_DIR)/ft_count_words.c \
            $(CONV_DIR)/ft_itoa.c

IS_SRCS = $(IS_DIR)/ft_isalpha.c \
          $(IS_DIR)/ft_isdigit.c \
          $(IS_DIR)/ft_isalnum.c \
          $(IS_DIR)/ft_isascii.c \
          $(IS_DIR)/ft_isprint.c \
          $(IS_DIR)/ft_isspace.c \
          $(IS_DIR)/ft_toupper.c \
          $(IS_DIR)/ft_tolower.c

MEM_SRCS = $(MEM_DIR)/ft_memset.c \
           $(MEM_DIR)/ft_bzero.c \
           $(MEM_DIR)/ft_memcpy.c \
           $(MEM_DIR)/ft_memccpy.c \
           $(MEM_DIR)/ft_memmove.c \
           $(MEM_DIR)/ft_memchr.c \
           $(MEM_DIR)/ft_memcmp.c \
           $(MEM_DIR)/ft_calloc.c \
           $(MEM_DIR)/ft_realloc.c

PUT_SRCS = $(PUT_DIR)/ft_putchar.c \
           $(PUT_DIR)/ft_putstr.c \
           $(PUT_DIR)/ft_putnbr.c \
           $(PUT_DIR)/ft_putchar_fd.c \
           $(PUT_DIR)/ft_putstr_fd.c \
           $(PUT_DIR)/ft_putendl_fd.c \
           $(PUT_DIR)/ft_putnbr_fd.c

STR_SRCS = $(STR_DIR)/ft_strlen.c \
           $(STR_DIR)/ft_strchr.c \
           $(STR_DIR)/ft_strrchr.c \
           $(STR_DIR)/ft_strcmp.c \
           $(STR_DIR)/ft_strncmp.c \
           $(STR_DIR)/ft_strnstr.c \
           $(STR_DIR)/ft_strlcpy.c \
           $(STR_DIR)/ft_strlcat.c \
           $(STR_DIR)/ft_strdup.c \
           $(STR_DIR)/ft_strndup.c \
           $(STR_DIR)/ft_substr.c \
           $(STR_DIR)/ft_strjoin.c \
           $(STR_DIR)/ft_strtrim.c \
           $(STR_DIR)/ft_split.c \
           $(STR_DIR)/ft_strmapi.c \
           $(STR_DIR)/ft_striteri.c

LISTS_SRCS = $(LISTS_DIR)/ft_lstnew.c \
             $(LISTS_DIR)/ft_lstadd_front.c \
             $(LISTS_DIR)/ft_lstsize.c \
             $(LISTS_DIR)/ft_lstlast.c \
             $(LISTS_DIR)/ft_lstadd_back.c \
             $(LISTS_DIR)/ft_lstdelone.c \
             $(LISTS_DIR)/ft_lstclear.c \
             $(LISTS_DIR)/ft_lstiter.c \
             $(LISTS_DIR)/ft_lstmap.c

# All source files 
SRCS = $(CONV_SRCS) $(IS_SRCS) $(MEM_SRCS) $(PUT_SRCS) $(STR_SRCS)

# Bonus source files
BONUS_SRCS = $(LISTS_SRCS)

# Object files
OBJ_DIR = obj
OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRCS))

# Headers
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $^

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus