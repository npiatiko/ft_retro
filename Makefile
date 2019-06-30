#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 14:42:08 by npiatiko          #+#    #+#              #
#    Updated: 2019/06/13 14:42:08 by npiatiko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

FLAGS = -Wall -Wextra #-Werror

SRCS = Game.cpp\
		Character.cpp\
		Marine.cpp\
		Squad.cpp\
		Fighter.cpp\
		Interceptor.cpp\
		Bomber.cpp\
		Raptor.cpp\
		Bullet.cpp\
		EnemyBullet.cpp

OBJ_DIR = ./obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADERS)
	clang++ -o $(NAME) $(OBJ) -lncurses

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	clang++ $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

#------------------------------- DEBUG -----------------------------------------
pr: print-OBJ_LIST print-HEADERS

print-%  : ; @echo $* = $($*)
#-------------------------------------------------------------------------------