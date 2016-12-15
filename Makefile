# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 13:46:14 by arosset           #+#    #+#              #
#    Updated: 2016/12/15 17:00:30 by vfrolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			=	includes
INCS			=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_DIR			=	src
SRC_BASE		=	main.c check.c ft_check_tetri.c ft_opencompare.c ft_create_lst.c \
					resolution_grid.c ft_resolution.c backtracking.c

OBJ_DIR			=	obj

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))


all : obj $(NAME)

$(NAME) : $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB_LINK)
	@echo "Compile" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<
	@echo "Obj" [ $< ] $(OK)

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Clean" [ $(NAME) ]  "..." $(OK)

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re : fclean all

.PHONY: all clean fclean re