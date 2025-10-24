NAME = push_swap
NAME1 = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./LIBFT
lib = $(LIB_DIR)/libft.a

sources = \
		main.c \
		parsing/libft_lst1.c \
		parsing/ft_parsing.c \
		parsing/ft_lstatoi.c \
		algo/operations.c \
		algo/arr_alloc.c \
		algo/push_swap_min.c \
		algo/push_swap_max.c \

bonus_src = \
		checker/checker.c \
		checker/ft_lstatoi.c \
		checker/ft_parsing.c \
		checker/operations.c \
		checker/libft_lst1.c

object = $(sources:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(lib):
	@make all -C $(LIB_DIR) > /dev/null 2>&1
	@echo "\033[32m	Libft Compiled Successfully! ✅\033[0m"

$(NAME): $(object) $(lib)
	@$(CC) $(CFLAGS) $(object) ./LIBFT/libft.a -o $(NAME)
	@echo "\033[32m	Push_swap Compiled Successfully! ✅\033[0m"

clean:
	@rm -rf $(object)
	@rm -rf $(bonus_obj)
	@make clean -C $(LIB_DIR) > /dev/null 2>&1
	@echo "\033[33m	Object Files Removed! 🗑️\033[0m"

bonus: $(NAME1)

$(NAME1): $(bonus_obj) $(lib)
	@$(CC) $(CFLAGS) $(bonus_obj) ./LIBFT/libft.a -o $(NAME1)
	@echo "\033[32m	Checker Compiled Successfully! ✅\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME1)
	@make fclean -C $(LIB_DIR) > /dev/null 2>&1
	@echo "\033[31m	Executable removed! ❌\033[0m"

re: fclean all

flush: re clean
	@make clean -C $(LIB_DIR) > /dev/null 2>&1
	@rm -rf $(object)

f: $(object)
	@$(CC) $(CFLAGS) $(object) ./LIBFT/libft.a -o $(NAME)
	@rm -rf $(object)
	@echo "\033[32m	Ready To Execute! ✅\033[0m"

.SECONDARY: $(object)
.PHONY: clean fclean re all
