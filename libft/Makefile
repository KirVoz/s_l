SRC = str/ft_atoi.c \
	  str/ft_bzero.c \
	  mem/ft_calloc.c \
	  str/ft_isalnum.c \
	  str/ft_isalpha.c \
	  str/ft_isascii.c \
	  str/ft_isdigit.c \
	  str/ft_isprint.c \
	  mem/ft_memchr.c \
	  mem/ft_memcmp.c \
	  mem/ft_memcpy.c \
	  mem/ft_memmove.c \
	  mem/ft_memset.c \
	  str/ft_strchr.c \
	  str/ft_strdup.c \
	  str/ft_strlcat.c \
	  str/ft_strlcpy.c \
	  str/ft_strlen.c \
	  str/ft_strncmp.c \
	  str/ft_strcmp.c \
	  str/ft_strnstr.c \
	  str/ft_strrchr.c \
	  str/ft_tolower.c \
	  str/ft_toupper.c \
	  str/ft_substr.c \
	  str/ft_strjoin.c \
	  str/ft_strtrim.c \
	  str/ft_split.c \
	  str/ft_itoa.c \
	  str/ft_strmapi.c \
	  str/ft_striteri.c \
	  str/ft_strncpy.c \
	  fd/ft_putchar_fd.c \
	  fd/ft_putstr_fd.c \
	  fd/ft_putendl_fd.c \
	  fd/ft_putnbr_fd.c \
	  get_next_line/get_next_line.c \
	  get_next_line/get_next_line_utils.c 

#BONUS = #list/ft_lstnew.c \
		list/ft_lstadd_front.c \
		list/ft_lstsize.c \
		list/ft_lstlast.c \
		list/ft_lstadd_back.c \
		list/ft_lstdelone.c \
		list/ft_lstclear.c \
		list/ft_lstiter.c 

OBJS = ${SRC:.c=.o}

#BONUS_OBJS = ${BONUS:.c=.o}

HEAD = ../libft.h

NAME = libft.a

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

#bonus: ${BONUS_OBJS}
#	${AR} -r ${NAME} $?

clean:
	@rm -f ${OBJS} 
#	${BONUS_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
