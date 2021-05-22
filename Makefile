NAME		=	push_swap

CHECKER_N	=	checker


TEST_N		=	tester

##############################################

SRCS		=	srcs/ft_swap.c\
				srcs/ft_strdup.c\
				srcs/ft_strlen.c\
				srcs/ft_putstr.c\
				srcs/ft_strcmp.c\
				srcs/ft_atoli.c\
				srcs/dlst_utils.c\
				srcs/push_swap.c\
				srcs/get_next_line.c\
				srcs/checker_utils.c\

MAIN_C		=	srcs/main.c
CHECKER_C	=	srcs/checker.c
TEST_C		=	srcs/test.c

#############################################

OBJS		=	${SRCS:.c=.o}

MAIN_O		=	${MAIN_C:.c=.o}
CHECKER_O	=	${CHECKER_C:.c=.o}
TEST_O		=	${TEST_C:.c=.o}

#############################################

HEADER		=	-I includes

CFLAGS		=	-Wall -Wextra -Werror

CC			=	clang

RM			=	rm -rf

#############################################

.c.o	:
				${CC} -g ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

#############################################

all		:	${NAME}
${NAME}	:	${MAIN_O} ${OBJS} 
				${CC} -g -o ${NAME} $(MAIN_O) ${OBJS} 

check	:	${CHECKER_N}
${CHECKER_N} :	${CHECKER_O} ${OBJS}
				${CC} -g -o ${CHECKER_N} $(CHECKER_O) ${OBJS}

test	:	${TEST_N}
${TEST_N} :	${TEST_O} ${OBJS}
				${CC} -g -o ${TEST_N} $(TEST_O) ${OBJS}

##############################################


clean	:
				${RM} ${OBJS} ${MAIN_O} ${CHECKER_O} ${TEST_O}

fclean	:	clean
				${RM} ${NAME} ${CHECKER_N} ${TEST_N}

re		:	fclean all

.PHONY	:	all clean fclean sclean re
