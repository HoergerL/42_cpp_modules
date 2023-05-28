NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
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

check: re
	./$(NAME) $(shuf -i 1-10000 -n 3000 | tr "\n" " ") | grep After | cut -d ":" -f2 |  tr " " "\n" |  grep . | sort -nc && echo OK || echo Fail
	# echo After: $$(shuf -i 1-1000 -n 300 | tr "\n" " ") | grep After | cut -d ":" -f2 |  tr " " "\n" |  grep . | sort -nc && echo Fail || echo OK
