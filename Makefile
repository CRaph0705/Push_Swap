# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:47:30 by rcochran          #+#    #+#              #
#    Updated: 2025/01/31 12:49:28 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar rcs
NAME		= 	push_swap.a

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

HEADER 		= 	$(LIBFT_PATH)/includes \
				$(SRC_DIR)

FILES		= 	

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
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

test: all
	$(CC) src/main.c -c -I$(HEADER) -o obj/main.o
	$(CC) obj/main.o -L. -lftprintf -o obj/a.out

