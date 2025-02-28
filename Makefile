# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:47:30 by rcochran          #+#    #+#              #
#    Updated: 2025/02/26 13:30:18 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar -rcs
NAME		= 	push_swap

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDES	= -I$(LIBFT_PATH)/includes -I ./includes

FILES		= 	chunk_sort_utils \
				chunk_sort \
				converter \
				converter_utils \
				display \
				error_handler \
				exit \
				get_node_by \
				init \
				insertion_sort_utils \
				insertion_sort \
				main \
				parse \
				push_swap_utils \
				push_swap \
				push \
				rapid_sort \
				reverse_rotate \
				rotate \
				smarter_sort \
				sort \
				stacks_functions \
				stacks_functions2 \
				stacks_utils \
				swap \
				target_position

SRC_FILES	=	$(addsuffix .c, $(FILES))
OBJ_DIR		= obj/
SRC_DIR		= src/
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re : fclean all

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

debug : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

