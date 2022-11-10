DIRLIBFT		= ./libft/

SRCS	= ft_printf.c \
		ft_printf_char.c \
		ft_printf_hex.c \
		ft_printf_num.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

NAMELIBFT		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIBFT} && ${MAKE} && cp ${NAMELIBFT} ../${NAME}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}
			cd ${DIRLIBFT} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME)
			cd ${DIRLIBFT} && ${MAKE} fclean

re:			fclean all