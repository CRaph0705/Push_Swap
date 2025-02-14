# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:47:30 by rcochran          #+#    #+#              #
#    Updated: 2025/02/14 18:00:54 by rcochran         ###   ########.fr        #
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

FILES		= 	main converter display error_handler exit init instructions parse stacks_functions stacks_functions2 push_swap

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


