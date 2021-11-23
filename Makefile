CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

RM = rm -f

NAME = libftprintf.a 

SRC = 

SRC_BONUS = 

LIBFT_NAME = libft.a

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

LIBFTDIR = ./libft/

SRCWD = $(addprefix src/, ${SRC})

SRCWD_BONUS = $(addprefix src/, ${SRC_BONUS})

SOURCES = ft_printf.c ${SRCWD}

SOURCES_BONUS = ft_printf_bonus.c ${SRCWD_BONUS}

OBJS = $(patsubst %.c, %.o, ${SOURCES})

OBJS_BONUS = $(patsubst %.c, %.o, ${SOURCES_BONUS})

.PHONY:	clean all bonus fclean re

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

%.o :	%.c ${HEADERS}
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} $?

bonus:
	make OBJS="${OBJS_BONUS} ${OBJS}" all

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

