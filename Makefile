CC = gcc

SRCS = ft_printf.c
OBJS = $(SRCS:%.c=%.o)	

TEST_SRCS = $(SRCS) tests/test.c
TEST_OBJS = $(TEST_SRCS:%.c=%.o)

// CFLAGS = -Wall -Wextra -Werror


test: $(TEST_OBJS)
	gcc -o $@ $^

.PHONY: test
