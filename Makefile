CC := cc
CFLAGS := -Wall -Wextra -Werror -g

# Compile client.c and server.c
all: libft client server

client: client.o
	$(CC) $(CFLAGS) -o client client.o libft/libft.a

server: server.o
	$(CC) $(CFLAGS) -o server server.o libft/libft.a

# Compile libft using its Makefile
libft:
	$(MAKE) -C libft

# Create objs directory if it does not exist
objs:
	mkdir -p objs

# Move object files to objs folder
objs/client.o: objs client.c
	$(CC) $(CFLAGS) -c client.c -o objs/client.o

objs/server.o: objs server.c
	$(CC) $(CFLAGS) -c server.c -o objs/server.o

clean:
	rm -f client server objs/*.o
	$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re objs