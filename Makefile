CC=cc
CFLAGS=-Wall -Wextra -Werror -g
SOURCEFILES=ft_atol.c ft_find_last.c ft_stack_init.c utils.c push_swap.c ft_split.c ft_stack_sorted.c ft_stack_len.c swap.c push.c rotate.c rev_rotate.c ft_min_max.c ft_sort_three.c ft_free_stack.c prep_for_push.c stack_utils_a.c stack_utils.c ft_sort_stacks.c stack_utils_b.c
OBJECTS=$(patsubst %.c,objects/%.o,$(SOURCEFILES))
NAME=push_swap
BONUS_SRC=checker.c ft_atol.c ft_find_last.c ft_stack_init.c utils.c ft_split.c ft_stack_sorted.c ft_stack_len.c swap.c push.c rotate.c rev_rotate.c ft_min_max.c ft_sort_three.c ft_free_stack.c prep_for_push.c stack_utils_a.c stack_utils.c ft_sort_stacks.c stack_utils_b.c
BONUS_OBJ=$(patsubst %.c,objects/%.o,$(BONUS_SRC))
BONUS_NAME=checker
OBJDIR=objects

all: $(OBJDIR) $(OBJECTS) $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	$(MAKE) -C libft/
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L. -lft

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) -L. -lft

bonus: all $(BONUS_NAME)

clean:
	$(MAKE) -C libft/ clean
	rm -f libft.a $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
