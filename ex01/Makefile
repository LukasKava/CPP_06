# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 16:22:27 by lkavalia          #+#    #+#              #
#    Updated: 2023/05/29 15:31:56 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serial

CC = g++

CPP_FLAGS =  -std=gnu++11 -Wall -Werror -Wextra -fsanitize=address #-std=c++98 

SRC = main.cpp \
		Serializer.cpp

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CPP_FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
	@echo "force cleaning!"

re: fclean all
	@echo "remaking files!"