NAME = bureaucrat
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
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
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all
