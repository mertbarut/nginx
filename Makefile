NAME=webserv

SRC=main.cpp

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98 -o

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) $(NAME)

clean:
	@rm -f ./*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re