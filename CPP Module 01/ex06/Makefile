CC = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp	\
		Harl.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = harlFilter

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re