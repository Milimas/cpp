CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		AMateria.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = Interface

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re