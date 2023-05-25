# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 14:08:59 by lkavalia          #+#    #+#              #
#    Updated: 2023/05/25 14:09:47 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar

CC = c++

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRC = main.cpp \
		ScalarConverter.cpp

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CPP_FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
	@echo "force cleaning!"

re: fclean all
	@echo "remaking files!"