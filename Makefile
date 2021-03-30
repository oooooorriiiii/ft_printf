CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		ft_pf_utils.c \
		ft_pf_format.c \
		ft_pf_parser.c \
		ft_pf_flag.c \
		ft_pf_width.c \
		ft_pf_prec.c \
		ft_pf_dec.c		\
		ft_pf_hex.c		\
		ft_pf_ptr.c		\
		ft_pf_out_char.c \
		ft_pf_out_str.c \
		ft_pf_out_nbr.c
OBJS = $(SRCS:%.c=%.o)	

TEST_OBJS = $(TEST_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
