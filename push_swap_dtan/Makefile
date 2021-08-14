NAME = push_swap

BONUS = checker

SRCS = srcs/push_swap/ft_push_swap.c srcs/push_swap/ft_parser.c srcs/push_swap/ft_stack.c srcs/push_swap/ft_instruction_utils.c \
		srcs/push_swap/ft_swap.c srcs/push_swap/ft_push.c srcs/push_swap/ft_rotate.c srcs/push_swap/ft_reverse_rotate.c \
		srcs/push_swap/ft_sort.c srcs/push_swap/ft_sort_utils.c srcs/push_swap/ft_sort_base_case.c srcs/push_swap/ft_sort_base_case_utils.c
OBJS = $(SRCS:.c=.o)

COMMON_SRCS = srcs/push_swap/ft_parser.c srcs/push_swap/ft_stack.c srcs/push_swap/ft_instruction_utils.c \
		srcs/push_swap/ft_swap.c srcs/push_swap/ft_push.c srcs/push_swap/ft_rotate.c srcs/push_swap/ft_reverse_rotate.c \
		srcs/push_swap/ft_sort.c srcs/push_swap/ft_sort_utils.c srcs/push_swap/ft_sort_base_case.c srcs/push_swap/ft_sort_base_case_utils.c
COMMON_OBJS= $(COMMON_SRCS:.c=.o)

BONUS_SRCS = srcs/checker/ft_checker.c srcs/checker/ft_check_sorted.c srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

INCS = includes

LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_OPTIONS = -L$(LIBFT_DIR) -lft

OPTIONS = -I$(INCS)

all: $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR); make bonus; cd ..

%.o: %.c
	$(CC) -o $@ -c $^ $(FLAGS) $(OPTIONS)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $@ $(OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

$(BONUS): $(LIBFT) $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) -o $@ $(COMMON_OBJS) $(BONUS_OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean $(NAME) $(BONUS)

bonus: $(BONUS)

.PHONY: all clean fclean re bonus
