CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

SRC =	main.cpp					\
		Base.cpp					\

OBJ = $(SRC:.cpp=.o)

NAME = IdentifyRealType

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re