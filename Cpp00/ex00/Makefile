NAME = megaphone
SRC = megaphone.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror
MAKE = make

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@


clean:
	rm -f *.o *~
	rm -f *.out

fclean: clean
	rm -f $(NAME)

re: fclean all
