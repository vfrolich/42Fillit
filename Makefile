# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 13:46:14 by arosset           #+#    #+#              #
#    Updated: 2016/12/15 18:37:09 by vfrolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-Llibft -lft

SRC				=	main.c check.c ft_check_tetri.c ft_opencompare.c ft_create_lst.c \
					resolution_grid.c ft_resolution.c backtracking.c

HEADER 			=	fillit.h

OBJS			=	$(SRC:.c=.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[32m"

# MESSAGE
SUCCESS			=	$(C_OK)OK$(C_NO)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(LIB_LINK) $^ -o $@
	@echo ./$(NAME) : $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "Obj" [ $< ] $(SUCCESS)

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re : fclean all