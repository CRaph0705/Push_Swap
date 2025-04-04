# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:47:30 by rcochran          #+#    #+#              #
#    Updated: 2025/04/04 10:30:51 by rcochran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
AR			=	ar -rcs
NAME		= 	push_swap
BNAME		=	checker

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

INCLUDES	= -I$(LIBFT_PATH)/includes -I ./includes
BINCLUDES	=	-I ./bonus

FILES		= 	chunk_sort_utils \
				chunk_sort \
				converter \
				converter_utils \
				display \
				error_handler \
				get_node_by \
				get_node \
				init \
				insertion_sort_utils \
				insertion_sort \
				parse \
				push_swap \
				push \
				pushback \
				reverse_rotate \
				rotate \
				smarter_sort \
				sort_short \
				stacks_functions \
				stacks_functions2 \
				stacks_utils \
				swap \
				target_position \
				utils \

BFILES		=	checker

MAIN		=	main.c
BMAIN		=	main_bonus.c
# OBJ_MAIN		= 	$(addprefix $(SRC_DIR), $(MAIN:.c=.o))
# OBJ_BMAIN		= 	$(addprefix $(SRC_BDIR), $(BMAIN:.c=.o))

SRC_FILES	=	$(addsuffix .c, $(FILES))
SRC_BFILES	= 	$(addsuffix .c, $(BFILES))

OBJ_DIR		= obj/
BOBJ_DIR	= bobj/

SRC_DIR		= src/
SRC_BDIR	= bonus/

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC		= 	$(addprefix $(SRC_BDIR), $(SRC_BFILES))

OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
BOBJ		=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(BSRC))

OBJ_MAIN	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_DIR)$(MAIN))
OBJ_BMAIN	=	$(patsubst $(SRC_BDIR)%.c, $(BOBJ_DIR)%.o, $(SRC_BDIR)$(BMAIN))

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f checker

re : fclean all

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_MAIN)
	$(CC) -g3 $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
# mkdir -p $(dir $@)
	$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BOBJ_DIR)%.o: $(SRC_BDIR)%.c
# mkdir -p $(dir $@)
	$(CC) -g3 $(CFLAGS) $(INCLUDES) $(BINCLUDES) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(BOBJ_DIR) : 
	mkdir -p $(BOBJ_DIR)

debug : $(LIBFT) $(OBJ_DIR) $(OBJ) Makefile
	$(CC) -g3 $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L$(LIBFT_PATH) -lft -o $(NAME)

checker: $(OBJ) $(BOBJ_DIR) $(BOBJ) $(OBJ_BMAIN)
	$(CC) $(CFLAGS) $(OBJ) $(BOBJ) $(OBJ_BMAIN) -L$(LIBFT_PATH) -lft -o checker

bonus: $(NAME) checker

rebonus: fclean bonus
