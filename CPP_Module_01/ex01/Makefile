CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Zombie.cpp		\
		zombieHorde.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = MoarBrainz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re