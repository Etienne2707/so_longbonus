# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: educlos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2023/05/23 15:02:17 by educlos          ###   ########.fr        #
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
	  $(SRC_DIR)/init.c					    \
  	  $(SRC_DIR)/movement.c					\
      $(SRC_DIR)/get_next_line.c	        \
	  $(SRC_DIR)/checker_map_utils.c        \

SRC_BONUS = $(SRC_BONUS_DIR)/checker_map_bonus.c		\
      		$(SRC_BONUS_DIR)/ft_split_bonus.c			\
     		$(SRC_BONUS_DIR)/gnl_utils_bonus.c			\
      		$(SRC_BONUS_DIR)/main_bonus.c				\
	  		$(SRC_BONUS_DIR)/path_check_bonus.c			\
  	  		$(SRC_BONUS_DIR)/event_bonus.c				\
	  		$(SRC_BONUS_DIR)/positions_bonus.c			\
	  		$(SRC_BONUS_DIR)/refresh_bonus.c			\
	  		$(SRC_BONUS_DIR)/compteur_bonus.c			\
	  		$(SRC_BONUS_DIR)/init_bonus.c				\
  	  		$(SRC_BONUS_DIR)/movement_bonus.c			\
      		$(SRC_BONUS_DIR)/get_next_line_bonus.c	    \
	  		$(SRC_BONUS_DIR)/checker_map_utils_bonus.c  \


OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(BIN_DIR)/%.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes


CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :	$(BIN_DIR) $(NAME)

bonus:	$(NAME_BONUS)

$(OBJ) :		$(BIN_DIR)%.o: $(SRC_DIR)/%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) :		$(BIN_DIR)%.o: $(SRC_BONUS_DIR)/%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(NAME_BONUS) :	$(BIN_DIR) $(OBJ_BONUS)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME_BONUS)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mBonus ! 💸"

$(BIN_DIR):
		@ mkdir -p $(BIN_DIR)

clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ)
		@ rm -f $(OBJ_BONUS)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@ rm -f $(NAME_BONUS)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all $(SRC_BONUS_DIR) clean fclean re