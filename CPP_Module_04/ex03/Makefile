CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

PREPROCFLAG = -E

SRC =	main.cpp		\
		AMateria.cpp	\
		Character.cpp	\
		MateriaSource.cpp	\
		Ice.cpp	\
		Cure.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = Interface

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

preproc:
	$(CXX) $(PREPROCFLAG) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
