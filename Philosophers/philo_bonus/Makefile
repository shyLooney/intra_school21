NAME = philo_bonus

SRCS 	= 	initalize_bonus.c \
			philo_bonus.c \
			utils_bonus.c 

HEADER	=	philo_bonus.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC 		= 	gcc
CFLAGG 	= 	-Wall -Wextra -Werror -I$(HEADER)

all		:	${NAME}

$(NAME)	:	$(OBJ)	$(HEADER)
	$(CC) $(CFLAGG) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

