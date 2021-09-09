# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 10:44:56 by skoh              #+#    #+#              #
#    Updated: 2021/09/08 22:59:52 by skoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
NAME2	:=	checker
libft	:=	libft/libft.a
makelib	:=	make -C libft
obj		:=	src/cast.o \
			src/commands.o \
			src/executor.o \
			src/parser.o
obj1	:=	src/ps_normalizer.o \
			src/ps_main.o \
			src/ps_solver.o \
			src/ps_sorter.o
obj2	:=	src/ck_main.o

# LDFLAGS	:=	-fsanitize=address
CFLAGS	:=	-Wall -Wextra -Werror $(LDFLAGS) #-g3
.PHONY	: all bonus clean fclean re force test eval

all bonus: $(NAME) $(NAME2)

clean:
	$(RM) $(obj) $(obj1) $(obj2)
	$(makelib) $@

fclean: clean
	$(RM) $(NAME) $(NAME2)
	$(makelib) $@

re: fclean all

$(NAME): $(obj) $(obj1) $(libft)
	$(LINK.o) $^ -o $@

$(NAME2): $(obj) $(obj2) $(libft)
	$(LINK.o) $^ -o $@

$(libft): force
	$(makelib) ARFLAGS="rs" CFLAGS="$(CFLAGS)"

eval: checker_Mac
	@echo [500]
	@echo -n 'ARG="'
	@jot -r 1000 -2147483648 2147483647 | sort | uniq | sort -R  |head -500 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG | ./checker_Mac $$ARG'
	@echo [100]
	@echo -n 'ARG="'
	@jot -r 1000 -2147483648 2147483647 | sort | uniq | sort -R  |head -100 | tr '\n' ' '
	@echo '"; ./push_swap $$ARG | ./checker_Mac $$ARG'
	@echo [Visualizer https://codepen.io/ahkoh/full/bGWxmVz]

checker_Mac:
	curl -sLO https://projects.intra.42.fr/uploads/document/document/4415/checker_Mac
	chmod +x $@

test: bonus
	git clone https://github.com/lmalki-h/push_swap_tester.git || true
	cd push_swap_tester/ && bash tester.sh .. 3 20 && read
	cd push_swap_tester/ && bash tester.sh .. 5 20 && read
	cd push_swap_tester/ && bash tester.sh .. 100 100 && read
	cd push_swap_tester/ && bash tester.sh .. 500 100
