NAME		=	checker

TEST_N		=	tester

##############################################

SRCS		=	srcs/ft_swap.c\
				srcs/ft_strdup.c\
				srcs/ft_strlen.c\
				srcs/ft_putstr.c\
				srcs/ft_strcmp.c\
				srcs/ft_atoli.c\
				srcs/get_next_line.c\
				srcs/dlst_utils.c\
				srcs/push_swap.c\

MAIN_C		=	srcs/main.c
TEST_C		=	srcs/test.c

#############################################

OBJS		=	${SRCS:.c=.o}

MAIN_O		=	${MAIN_C:.c=.o}
TEST_O		=	${TEST_C:.c=.o}

#############################################

HEADER		=	-I includes

CFLAGS		=	-Wall -Wextra -Werror

CC			=	clang

RM			=	rm -rf

#############################################

.c.o	:
				${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

#############################################

all		:	${NAME}
${NAME}	:	${MAIN_O} ${OBJS} 
				${CC} -o ${NAME} $(MAIN_O) ${OBJS} 

test	:	${TEST_N}
${TEST_N} :	${TEST_O} ${OBJS}
				${CC} -o ${TEST_N} $(TEST_O) ${OBJS}

##############################################


clean	:
				${RM} ${OBJS} ${MAIN_O} ${TEST_O}

fclean	:	clean
				${RM} ${NAME} ${TEST_N}

re		:	fclean all

.PHONY	:	all clean fclean sclean re
