CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Animal.cpp		\
		Cat.cpp			\
		Dog.cpp			\
		WrongCat.cpp	\
		WrongAnimal.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = Polymorphism

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re