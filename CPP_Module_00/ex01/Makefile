CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC =	main.cpp		\
		PhoneBook.cpp	\
		Contact.cpp		\

OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re