CC = gcc

SRCS = 	ft_printf.c \
		ft_pf_utils.c \
		ft_pf_format.c \
		ft_pf_parser.c \
		ft_pf_dec.c		\
		ft_pf_hex.c		\
		ft_pf_ptr.c		\
		ft_pf_output.c
OBJS = $(SRCS:%.c=%.o)	

TEST_SRCS = $(SRCS) tests/test.c
TEST_OBJS = $(TEST_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

test: $(TEST_OBJS)
	gcc -o $@ $^

clean:
	rm -f $(OBJS) $(TEST_OBJS)

.PHONY: test
