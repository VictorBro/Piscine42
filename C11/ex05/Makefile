NAME := do-op
FILES := do_op.c operators.c str_utils.c
INCLUDE_DIR := includes
INCLUDES := $(addprefix -I, $(INCLUDE_DIR))
CC := cc
CFLAGS := -Wall -Wextra -Werror 
OBJS := $(FILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
