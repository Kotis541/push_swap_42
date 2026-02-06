NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I Libft/Libft

LIBFT_DIR = Libft/Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
	src/other.c \
	src/parser.c \
	src/sort_small.c \
	src/sorts/double_rotate.c \
	src/sorts/sort_b.c \
	src/sorts/sorts_a.c \
	src/turk_algoritm/helper_func.c \
	src/turk_algoritm/turk.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re