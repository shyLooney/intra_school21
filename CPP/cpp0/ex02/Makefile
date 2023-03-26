NAME = Account

SRCS 	= 	Account.cpp \
			tests.cpp

CPP		= 	clang++
CFLAGG 	= 	-Wall -Wextra -Werror -std=c++98

all		:	${NAME}

$(NAME)	:	$(SRCS)
	$(CPP) $(CFLAGG) $(SRCS) -o $(NAME)

clean	:
	rm -f $(NAME)

re		:	clean all

