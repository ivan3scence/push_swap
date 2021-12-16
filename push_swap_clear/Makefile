CFLAGS = -Wall -Wextra -Werror

HDRS = pushswap.h

HDRS_DIR = includes/

CC = cc

RM = rm -f

NAME = push_swap

SRC = ps_five_sort.c  ps_opers2.c  ps_opers.c  ps_radix.c\
	ps_mkbeautiful.c  ps_three_sort.c  ps_validate.c  push_swap_main.c

SRC_DIR = src/

LIBFT_NAME = libft.a

LIBFTDIR = ./libft/

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

HEADERS = $(addprefix ${HDRS_DIR}, ${HDRS})

SOURCES = $(addprefix ${SRC_DIR}, ${SRC})

OBJS = $(patsubst %.c, %.o, ${SOURCES})

.PHONY:	clean all fclean re

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

%.o :	%.c ${HEADERS}
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${SOURCES}
	${CC} ${CFLAGS} ${SOURCES} -L ${LIBFTDIR} -lft -o $@

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean:		clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re:	fclean all

