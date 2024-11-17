# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:47:31 by adelattr          #+#    #+#              #
#    Updated: 2024/11/17 11:02:54 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS =	ft_printf.c 			\
		ft_printf_tools.c 		\
		ft_printf_basictools.c 	\
		ft_putflags.c 			

INCLUDES = ft_printf.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%o: %c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
