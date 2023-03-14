BIN=gnl.out
BUFFER_SIZE=5

CC=gcc
# CFLAGS=-Wall -Werror -Wextra
DEBUG_FLAGS=-fsanitize=address -g
SIZE_FLAG=-DBUFFER_SIZE=$(BUFFER_SIZE)

SRCS=get_next_line.c get_next_line_utils.c main.c
OBJS=$(SRCS:.c=.o)

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
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SIZE_FLAG) -o $@ -c $<
