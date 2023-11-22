SRC =  get_next_line.c get_next_line_utils.c
SRCB = get_next_line_utils_bonus.c get_next_line_utils_bonus.c
NAME = gnl.a
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $^

%.o: %.c get_next_line.h
	cc -Wall -Wextra -Werror -c $< -o $@

bonus: $(OBJB) get_next_line_bonus.h
	ar -rcs $(NAME) $<

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re