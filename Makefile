NAME=gnl.out

CC=gcc
CFLAGS=-Wall -Werror -Wextra

MAIN_C=main.c
SRCS=get_next_line.c get_next_line_utils.c $(MAIN_C)

.PHONY: all run clean $(NAME)

all: $(NAME)

run: $(NAME)
	@./$(NAME)

$(NAME):
	@$(CC) -g $(SRCS) -o $(NAME)

$(NAME)_strict:
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)_strict

clean:
	@rm -rf $(NAME)
