NAME = libft.a
SRC_DIR = srcs
FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = $(addprefix $(SRC_DIR)/, $(FILES))
INCLUDE_DIR = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRCS:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
