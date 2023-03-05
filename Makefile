BIN=gnl.out

CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEBUG_FLAGS=-fsanitize=address -g

SRCS=get_next_line.c get_next_line_utils.c main.c
OBJS=$(SRCS:.c=.o)

BUFFER_SIZE=42

.PHONY: all run clean fclean $(NAME)

all: $(NAME)

run: $(BIN)
	@./$(BIN)

clean:
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning all"
	@rm -f $(BIN)

re: fclean all

$(BIN): $(OBJS)
	@$(CC) $(DEBUG_FLAGS) -o $(BIN) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ -c $<
