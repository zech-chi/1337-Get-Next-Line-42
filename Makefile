SRC =  get_next_line.c get_next_line_utils.c
NAME = gnl.a
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $^

%.o: %.c get_next_line.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re