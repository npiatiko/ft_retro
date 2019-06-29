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

SRCS = main.cpp\
		Game.cpp\
		Sky.cpp\
		Character.cpp\
		Marine.cpp

OBJ = $(SRCS:.cpp=.o)

#INC = Contact.class.hpp\
#     PhoneBook.class.hpp

all: $(NAME)

$(NAME) : $(OBJ)
	clang++ -o $(NAME) $(OBJ) -lncurses

./%.o: ./%.cpp $(INC)
	clang++ $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f megaphone

re:	fclean all