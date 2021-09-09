SERVER	=	server
CLIENT	=	client
LIBFT	=	libft/libft.a
CFLAGS	=	gcc -g -Wall -Werror -Wextra -I.

all:
		@make -C ./libft
		@$(CFLAGS) server.c $(LIBFT) -o $(SERVER)
		@$(CFLAGS) client.c $(LIBFT) -o $(CLIENT)
		@echo "Compiling server.c & client.c..."

clean:
		@make clean -C ./libft
		@rm -f server.o client.o
		@echo "Removing object files..."

fclean:	clean
		@make fclean -C ./libft
		@rm -f $(SERVER) $(CLIENT)
		@echo "Removing program files..."

re:	fclean all

.PHONY:	all clean fclean re
