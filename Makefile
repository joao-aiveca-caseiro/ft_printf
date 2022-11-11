LIBFT		= ./libft/libft.a
SRCS	= ft_printf.c \
		ft_printf_char.c \
		ft_printf_hex.c \
		ft_printf_num.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKE} all -C ./libft
			cp ${LIBFT} ${NAME}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${RM} $(NAME)
			${MAKE} fclean -C ./libft 

re:			fclean all