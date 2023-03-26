NAME = stl

SRCS 	= 	main.cpp \
			Span.cpp

CPP		= 	c++
CFLAGG 	= 	-Wall -Wextra -Werror -std=c++98

all		:	${NAME}

$(NAME)	:	$(SRCS) Makefile
	$(CPP) $(CFLAGG) $(SRCS) -o $(NAME)

clean	:
	rm -f $(NAME)

re		:	clean all

