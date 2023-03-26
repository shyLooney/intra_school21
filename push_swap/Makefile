NAME = push_swap
NAME_CHECK = checker

SRCS 	= 	action.c \
			action2.c \
			action3.c \
			clear.c \
			main_sort.c \
			main.c \
			parser.c \
			parser2.c \
			parser3.c \
			small_sort.c \
			faster.c \
			faster2.c \
			utils.c

SRCS_CHECK	=	action.c \
			action2.c \
			action3.c \
			clear.c \
			main_sort.c \
			parser.c \
			parser2.c \
			parser3.c \
			small_sort.c \
			faster.c \
			faster2.c \
			utils.c \
			checker.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c 

HEADER	=	push_swap.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))
OBJ_CHECK		=	$(patsubst %.c, %.o, $(SRCS_CHECK))

CC 		= 	gcc
CFLAGG 	= 	-Wall -Wextra -Werror -I$(HEADER)

all		:	${NAME} ${NAME_CHECK}

$(NAME)	:	$(OBJ)	$(HEADER)
	$(CC) $(CFLAGG) $(OBJ) -o $(NAME)

$(NAME_CHECK)	:	$(OBJ_CHECK)	$(HEADER)
	$(CC) $(CFLAGG) $(OBJ_CHECK) -o $(NAME_CHECK)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ) $(OBJ_CHECK)

fclean	:	clean
	$(RM) $(NAME) $(NAME_CHECK)

re		:	fclean all

