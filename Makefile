# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 14:17:22 by nsamoilo          #+#    #+#              #
#    Updated: 2022/07/26 14:42:12 by nsamoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror

INCL = -Iincludes/ -I$(LIB_DIR)/includes

SRCS =	main.c char_array_manipulation.c parsing.c validation.c testing.c \
sorting.c check_duplicates.c room.c search.c links_parsing.c linked_list.c \
flow.c links.c input_forks.c output_forks.c result.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/

all: $(NAME)

debug: FLAGS += -g
debug: re
no_flags: FLAGS = -w -g
no_flags: re

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	@echo "Compiled Lem-in"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INCL)

clean:
	@make clean -C $(LIB_DIR) --silent
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR) --silent
	@echo "Removed executables"

re: fclean all

rm_all:
	@rm $(LIB_DIR)*.o
	@rm $(LIB_DIR)*.a
	@rm -rf ./objs
	@rm -f lem-in*
	@echo "Removed all exes and objects"

.PHONY: all clean fclean re
