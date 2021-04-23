NAME		=	checker

SRCS		=	srcs/main.c\
				srcs/ft_swap.c\
				srcs/ft_strdup.c\
				srcs/ft_strlen.c\
				srcs/ft_putstr.c\
				srcs/ft_strcmp.c\
				srcs/get_next_line.c\
				srcs/dlst_utils.c\
				srcs/push_swap.c\



OBJS		=	${SRCS:.c=.o}

HEADER		=	-I includes

CFLAGS		=	-Wall -Wextra -Werror

CC			=	clang

RM			=	rm -rf



.c.o	:
				${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all		:	${NAME}

${NAME}	:	${OBJS} 
				${CC} -o ${NAME} ${OBJS} 

clean	:
				${RM} ${OBJS}

fclean	:	clean
				${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean sclean re