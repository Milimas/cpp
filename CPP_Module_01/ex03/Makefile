CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Weapon.cpp		\
		HumanA.cpp		\
		HumanB.cpp		\

OBJ = $(SRC:.cpp=.o)

NAME = UnnecessaryViolence

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re