NAME = push_swap
BONUS_NAME = checker
LIBRARY = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
MAKE = make -sC

LIBFT_D = ./libft
LIBFT = $(LIBFT_D)/libft.a

SRC = src/push_swap.c \
	src/node1.c \
	src/node2.c \
	src/utils1.c \
	src/utils2.c \
	src/utils3.c \
	src/verifications.c \
	src/move_push.c \
	src/move_reverse_rotate.c \
	src/move_swap.c \
	src/move_rotate.c \
	src/algorithm.c \
	src/algorithm_path.c

BONUS_SRC = bonus_checker.c \
	bonus_moves.c \
	bonus_moves2.c

OBJ = $(SRC:src/%.c=obj/%.o)

BONUS_OBJ = $(BONUS_SRC:src/%.c=obj/%.o)

all: $(LIBRARY)

run:
	@$(CC) $(CFLAGS) -g $(SRC) $(LIBRARY) -o $(NAME)
	@echo "\e[1;32m####################################\e[0m"
	@echo "\e[1;32m#### [✓] Successful compilation ####\e[0m"
	@echo "\e[1;32m####################################\n\e[0m"

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[1;32m##########################\e[0m"
	@echo "\e[1;32m#### Objects creation ####\e[0m"
	@echo "\e[1;32m##########################\n\e[0m"

$(LIBRARY): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(LIBRARY)
	@$(AR) $(LIBRARY) $(OBJ)
	@echo "\e[1;32m#############################################\e[0m"
	@echo "\e[1;32m#### [✓] Library [ $(LIBRARY) ] created ####\e[0m"
	@echo "\e[1;32m#############################################\n\e[0m"

$(LIBFT):
	@$(MAKE) $(LIBFT_D)

$(BONUS_NAME): $(OBJ) $(BONUS_OBJ) $(LIBRARY)
	@ar rcs $(LIBRARY) $^
	@$(CC) $(CFLAGS) -g $(BONUS_SRC) $(LIBRARY) -o $(BONUS_NAME)
	@echo "\e[1;32m################################\e[0m"
	@echo "\e[1;32m###### [✓] checker created #####\e[0m"
	@echo "\e[1;32m################################\n\e[0m"
	@echo "\e[1;32m###################################\e[0m"
	@echo "\e[1;32m###### [✓] Library actualized #####\e[0m"
	@echo "\e[1;32m###################################\n\e[0m"

bonus: $(BONUS_NAME)

removep:
	@$(RM) $(BONUS_NAME)
	@$(RM) $(NAME)
	@echo "\e[1;31m#########################################\e[0m"
	@echo "\e[1;31m######### [x] programs deleted #########\e[0m"
	@echo "\e[1;31m#########################################\n\e[0m"

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@$(RM) -rf obj
	@make clean -sC $(LIBFT_D)
	@echo "\e[1;31m#########################################\e[0m"
	@echo "\e[1;31m#### [x] Objects and program deleted ###\e[0m"
	@echo "\e[1;31m#########################################\n\e[0m"

fclean: clean
	@$(RM) $(LIBRARY)
	@make fclean -sC $(LIBFT_D)
	@echo "\e[1;31m#########################################\e[0m"
	@echo "\e[1;31m#### [x] Library and Objects deleted ###\e[0m"
	@echo "\e[1;31m#########################################\n\e[0m"

re: fclean all

.PHONY: all clean fclean re