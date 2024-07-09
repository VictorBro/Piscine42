NAME = bsq
SRC_DIR =
FILES = main.c helpers_1.c helpers_2.c
INCLUDE_DIR =
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
OBJECTS = $(FILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
