# The output binary name
NAME = rush-02

# List of source files
SRCS = $(wildcard *.c)

# Corresponding object files for each source file
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g -Wall -Wextra -Werror

# Build the final program
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Building object files from C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
# Clean the object files
clean:
	rm -f $(OBJS)

.PHONY: fclean
# Clean object files and the final binary
fclean: clean
	rm -f $(NAME)

