# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 09:12:22 by teojimen          #+#    #+#              #
#    Updated: 2023/12/12 09:12:22 by teojimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -pthread -Wall -Wextra -Werror -g
# -fsanitize=address

SRC =	src/philo.c src/inputs.c src/utils.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile includes/philo.h
			${CC} ${FLAGS} -I ./ -c $< -o $@

$(NAME):	${OBJECTS}
		${CC} ${FLAGS} -o ${NAME} ${OBJECTS}
all: $(NAME)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: 	all clean fclean re