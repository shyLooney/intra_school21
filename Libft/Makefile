NAME = libft.a

SRC = ft_bzero.c   \
		ft_memchr.c  \
		ft_memcmp.c  \
		ft_memcpy.c  \
		ft_memmove.c \
		ft_memset.c  \
		ft_strchr.c  \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c  \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_striteri.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c    \
		ft_calloc.c  \
		ft_strdup.c  \
		ft_substr.c  \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c   \
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c
SRC_BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJ = $(SRC:.c=.o)

DFILES= $(patsubst %.c,%.d,$(SRC) $(SRC_BONUS))

OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(NAME) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
	@ranlib $(NAME)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -MD

include $(wildcard $(DFILES))

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(DFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
