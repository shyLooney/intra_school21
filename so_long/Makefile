NAME = so_long

SRCS		=	so_long.c \
				utils/check_map.c \
				utils/checker.c \
				utils/error_clear.c \
				utils/initalize_map.c \
				utils/map.c \
				utils/press_key.c \
				utils/move.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

HEADER	=	so_long.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC 		= 	gcc
CFLAGG 	= 	-Wall -Wextra -Werror -I$(HEADER)
MLXFLAGS	=	-L minilibx/ -lmlx -framework OpenGL -framework AppKit -lz


all		:	${NAME}

$(NAME)	:	$(OBJ)	$(HEADER)
	$(CC) $(CFLAGG) ft_printf/libftprintf.a $(MLXFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

