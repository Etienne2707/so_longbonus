# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: educlos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2023/02/08 17:11:03 by educlos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = better_so_long

SRC_DIR = src

SRC_BONUS_DIR = bonus

BIN_DIR = bin

SRC = $(SRC_DIR)/checker_map.c				\
      $(SRC_DIR)/ft_split.c					\
      $(SRC_DIR)/gnl_utils.c				\
      $(SRC_DIR)/main.c						\
	  $(SRC_DIR)/path_check.c				\
  	  $(SRC_DIR)/event.c					\
	  $(SRC_DIR)/positions.c				\
	  $(SRC_DIR)/refresh.c					\
	  $(SRC_DIR)/compteur.c					\
	  $(SRC_DIR)/init.c					     \
  	  $(SRC_DIR)/movement.c					     \



OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :	$(NAME)

$(BIN_DIR):
		@ mkdir -p $(BIN_DIR)

$(OBJ) :		$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(BIN_DIR)
		@ $(CC) $(CFLAGS) -c $< -o $@


$(NAME) :	$(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all clean fclean re