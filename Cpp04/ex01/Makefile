NAME = animals_with_brains
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
MAKE = make

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -c
	$(CC) $(CFLAGS) *.o -o $(NAME)

clean:
	rm -f *.o *~
	rm -f *.out
	rm -f *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
