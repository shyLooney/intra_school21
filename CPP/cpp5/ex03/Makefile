NAME = bur

SRCS 	= 	main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp

CPP		= 	c++
CFLAGG 	= 	-Wall -Wextra -Werror -std=c++98

all		:	${NAME}

$(NAME)	:	$(SRCS) Makefile
	$(CPP) $(CFLAGG) $(SRCS) -o $(NAME)

clean	:
	rm -f $(NAME)

re		:	clean all

