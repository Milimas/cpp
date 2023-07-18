CC = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Fixed.cpp		\

OBJ = $(SRC:.cpp=.o)

NAME = Fixed

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re