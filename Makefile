BIN=gnl.out
BIN_BONUS=gnl_bonus.out
BUFFER_SIZE=5

CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEBUG_FLAGS=-fsanitize=address -g -fno-builtin
SIZE_FLAG=-DBUFFER_SIZE=$(BUFFER_SIZE)

SRC_TEST=main.c
SRCS=get_next_line.c get_next_line_utils.c
SRCS_BONUS=get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_TEST=$(SRC_TEST:.c=.o)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

.PHONY: all run clean fclean $(NAME)

all: $(NAME)

bonus: $(OBJS_BONUS)

run: $(BIN)
	@./$(BIN)
	
run_bonus: $(BIN_BONUS)
	@./$(BIN_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "Cleaning all"
	@rm -f $(BIN)

re: fclean all

$(BIN): $(OBJS)
	@$(CC) $(DEBUG_FLAGS) -o $(BIN) $(OBJS) $(SRC_TEST)

$(BIN_BONUS): $(OBJS_BONUS)
	@$(CC) $(DEBUG_FLAGS) -o $(BIN_BONUS) $(OBJS_BONUS) $(SRC_TEST)

%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SIZE_FLAG) -o $@ -c $<
