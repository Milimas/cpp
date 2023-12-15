CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp					\
		Bureaucrat.cpp				\
		AForm.cpp					\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp		\
		PresidentialPardonForm.cpp	\
		Intern.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = Intern

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re