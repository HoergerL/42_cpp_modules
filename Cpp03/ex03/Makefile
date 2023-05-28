NAME = diamond_trap
SRC = main.cpp ClapTrap.cpp main.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow
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
