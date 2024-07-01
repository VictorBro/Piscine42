NAME := ft_display_files
FILES := ft_display_file.c
CC := cc
CFLAGS := -Wall -Wextra -Werror
OBJS := $(FILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
