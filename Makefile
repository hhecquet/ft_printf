# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:47:31 by adelattr          #+#    #+#              #
#    Updated: 2024/09/25 16:10:58 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes -g3

SRCS =	srcs/main.c	\
		srcs/check_dict.c \
		srcs/create_tab.c \
		srcs/create_tab2.c \
		srcs/ft_strdup.c \
		srcs/ft_aff.c \
		srcs/ft_send.c  \
		srcs/ft_send_2.0.c

INCLUDES = includes/ft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%o: %c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
