# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:11:04 by kvoznese          #+#    #+#              #
#    Updated: 2024/06/17 21:50:44 by kvoznese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/so_long.c \
		src/parser.c \
		src/init.c \
		src/flood_fill.c \
		src/end_game_options.c \
		src/start_game.c \
		src/put_images.c \
		src/moves.c \
		src/move_helper.c


OBJS = $(SRC:.c=.o)

HEAD = so_long.h

NAME = so_long

MAKE_MLX = cd ./Minilibx/ && make

MAKE_LIB = cd ./libft/ && make

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

RM = rm -rf

LIBFT = ft

LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE_MLX)
	@$(MAKE_LIB)
	@echo "Compiling so_long..."
	@$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a ./Minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Completed! 🤠"
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./Minilibx
	@echo "Completed! 😈"
	
clean:
	@$(RM) - $(NAME)
	@make clean -C libft
	@$(RM) -rf libft/libft.a
	@rm -f ${OBJS}

re: 	fclean all

.PHONY: all clean fclean re