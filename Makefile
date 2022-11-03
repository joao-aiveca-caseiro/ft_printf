SRCS = ft_printf.c
#BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${SRCS:.c=.o}
#BONUS_OBJS = ${BONUS_SRCS:.c=.o}
INCS = includes/
NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: 	${OBJS}
			${LIBC} ${NAME} ${OBJS}

all:	
		${MAKE} all -C ./libft 
		${MAKE} ${NAME}

#bonus:	${OBJS} $(BONUS_OBJS)
#		${LIBC} $(NAME) ${OBJS} $(BONUS_OBJS)

clean: 
		${MAKE} clean -C ./libft
		${RM} ${OBJS}


fclean: 
		${MAKE} clean -C ./libft
		${MAKE} clean
		${RM} ${NAME}

re: fclean all