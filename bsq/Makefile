NAME = bsq
SRC_DIR =
FILES = main.c dp.c helpers_1.c helpers_2.c helpers_3.c helpers_4.c
INCLUDE_DIR =
CC = cc
CFLAGS = -Wall -Wextra -Werror
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
