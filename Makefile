# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 13:01:41 by jemonthi          #+#    #+#              #
#    Updated: 2025/12/05 13:04:23 by jemonthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC	=		cc

CFLAGS	=	-Wall -Wextra -Werror

SOURCES	=	sources/push_swap.c \
		 	sources/operation.c \
		 	sources/operation_two.c \
			sources/get_into_list.c \
			sources/ft_split.c \
			sources/error_functions.c \
			sources/reverse_rotate.c \
			sources/sort_radix_and_free.c \
			sources/swap_stack.c \
			sources/utility_functions.c \
			sources/verification.c \
			sources/sort_low_size.c 


OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re
