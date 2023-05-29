CC = g++

CFLAGS += -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Zombie.cpp		\
		newZombie.cpp	\
		randomChump.cpp	\

OBJ = $(SRC:.cpp=.o)

NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	echo $(OBJ)

