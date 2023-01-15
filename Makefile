NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFTDIR)
LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = $(PWD)/libft

SRCS = \
main.c\
init.c\
check_error.c\
compress_array.c\
control_list_1.c\
control_list_2.c\
control_list_3.c\
utils_1.c\
sort_radix.c\
sort_ministack.c\
print_dlist.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	cd $(LIBFTDIR) && make bonus

.PHONY:
	all clean bonus fclean re;

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean

bonus:
	make WITH_BONUS=1

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re:fclean all