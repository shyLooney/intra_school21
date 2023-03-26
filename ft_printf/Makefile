NAME = libftprintf.a

SRC = ft_printf.c   \
		output_csp.c  \
		output_diuxX.c

OBJ = $(SRC:.c=.o)

DFILES= $(patsubst %.c,%.d,$(SRC))

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -MD

include $(wildcard $(DFILES))

clean:
	rm -f $(OBJ) $(DFILES)

fclean:		clean 
	rm -f ${NAME}

re: fclean all