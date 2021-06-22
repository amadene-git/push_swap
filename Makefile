NAME		=	push_swap

CHECKER_N	=	checker

##############################################

SRCS		=	srcs/ft_swap.c\
				srcs/ft_strdup.c\
				srcs/ft_strlen.c\
				srcs/ft_putstr.c\
				srcs/ft_strcmp.c\
				srcs/ft_atoli.c\
				srcs/dlst_utils.c\
				srcs/dlst_utils_2.c\
				srcs/push_swap.c\
				srcs/checker_utils.c\
				srcs/checker_utils_2.c\
				srcs/checker_utils_3.c\
				srcs/push_swap_utils.c\
				srcs/main_utils.c\
				srcs/main_utils2.c\
				srcs/main_utils3.c\
				srcs/Get_Next_Line/get_next_line.c\
				srcs/Get_Next_Line/get_next_line_utils.c\

MAIN_C		=	srcs/main.c
CHECKER_C	=	srcs/checker.c

#############################################

OBJS		=	${SRCS:.c=.o}

MAIN_O		=	${MAIN_C:.c=.o}
CHECKER_O	=	${CHECKER_C:.c=.o}

#############################################

HEADER		=	-I includes

CFLAGS		=	-Wall -Wextra -Werror -g

CC			=	clang

RM			=	rm -rf

#############################################

.c.o	:
				${CC}  ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

#############################################

all		:	${NAME}
${NAME}	:	${MAIN_O} ${OBJS} 
				${CC} -o ${NAME} $(MAIN_O) ${OBJS} 

check	:	${CHECKER_N}
${CHECKER_N} :	${CHECKER_O} ${OBJS}
				${CC} -o ${CHECKER_N} $(CHECKER_O) ${OBJS}

##############################################

clean	:
				${RM} ${OBJS} ${MAIN_O} ${CHECKER_O} ${TEST_O}

fclean	:	clean
				${RM} ${NAME} ${CHECKER_N} ${TEST_N}

re		:	fclean all

.PHONY	:	all clean fclean sclean re
