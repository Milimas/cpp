CC = c++

CPPFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

SRC =	main.cpp		\
		ClapTrap.cpp	\
		FragTrap.cpp	\
		ScavTrap.cpp	\
		DiamondTrap.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = DiamondTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re