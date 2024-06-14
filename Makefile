# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:11:04 by kvoznese          #+#    #+#              #
#    Updated: 2024/06/14 17:09:32 by kvoznese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long.c \
		parser.c \
		init.c \
		flood_fill.c \
		#star_game.c

OBJS = $(SRC:.c=.o)

HEAD = so_long.h

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

RM = rm -rf

LIBFT = ft

LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJS)
#	$(MAKE) bonus -C libft
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Completed! 🤠"
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo "Completed! 😈"
	
clean:
	@$(RM) - $(NAME)
	@make clean -C libft
	@$(RM) -rf libft/libft.a
	@rm -f ${OBJS}

re: 	fclean all

.PHONY: all clean fclean re