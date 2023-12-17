CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp	\
		Sed.cpp		\

OBJ = $(SRC:.cpp=.o)

NAME = Sed

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re