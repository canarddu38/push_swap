NAME			= push_swap
BONUS			= checker
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= libft
INCLUDE			= -I$(LIBFT_DIR) -Iinclude
OBJ_DIR			= obj

LIBFT_SRC		= ft_atoi.c \
				  ft_bzero.c \
				  ft_calloc.c \
				  ft_isalnum.c \
				  ft_isalpha.c \
				  ft_isascii.c \
				  ft_isdigit.c \
				  ft_isprint.c \
				  ft_itoa.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_memcpy.c \
				  ft_memmove.c \
				  ft_memset.c \
				  ft_split.c \
				  ft_strchr.c \
				  ft_strdup.c \
				  ft_strjoin.c \
				  ft_strlcat.c \
				  ft_strlcpy.c \
				  ft_strlen.c \
				  ft_strncmp.c \
				  ft_strnstr.c \
				  ft_strrchr.c \
				  ft_strtrim.c \
				  ft_substr.c \
				  ft_tolower.c \
				  ft_toupper.c \
				  ft_strmapi.c \
				  ft_striteri.c \
				  ft_putchar_fd.c \
				  ft_putstr_fd.c \
				  ft_putendl_fd.c \
				  ft_putnbr_fd.c
LIBFT_SRC		:= $(patsubst $(LIBFT_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIBFT_SRC))


PRINTF_C_FILES	= printf/count_functions.c \
				  printf/ft_printf.c \
				  printf/ft_putchar_count.c \
				  printf/ft_puthex_count.c \
				  printf/ft_putnbr_count.c \
				  printf/ft_putptr_count.c \
				  printf/ft_uint_putnbr_count.c \
				  printf/math.c \
				  printf/parser.c \
				  printf/types_display.c

UTILS_C_FILES	= utils/get.c \
				  utils/push.c \
				  utils/rotate_r.c \
				  utils/rotate.c \
				  utils/swap.c \
				  utils/utils.c \
				  utils/utils_next.c \
				  parser.c

C_FILES			= main.c \
				  bench.c \
			 	  algorithms/simple.c \
			 	  algorithms/medium.c \
				  algorithms/complex.c \
				  algorithms/adaptive.c \
				  $(PRINTF_C_FILES) \
				  $(UTILS_C_FILES) \
				  $(LIBFT_SRC)

BONUS_C_FILES	= checker_bonus/main_bonus.c \
				  checker_bonus/visual_bonus.c \
				  checker_bonus/parse_op_bonus.c \
				  $(PRINTF_C_FILES) \
				  $(UTILS_C_FILES) \
				  $(LIBFT_SRC)

O_FILES			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(C_FILES))
BONUS_O_FILES	= $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_C_FILES))

D_FILES			= $(O_FILES:.o=.d) $(BONUS_O_FILES:.o=.d)

all: $(OBJ_DIR) $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_O_FILES)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(O_FILES)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDE) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDE) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all re clean fclean bonus

-include $(D_FILES)
