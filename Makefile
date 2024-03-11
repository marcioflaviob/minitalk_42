CC := cc
CFLAGS := -Wall -Wextra -Werror -g

all: libft client server

client: objs/client.o
	$(CC) $(CFLAGS) -o client objs/client.o libft/libft.a

server: objs/server.o
	$(CC) $(CFLAGS) -o server objs/server.o libft/libft.a

libft:
	$(MAKE) -C libft

objs:
	mkdir -p objs

objs/client.o: objs client.c
	$(CC) $(CFLAGS) -c client.c -o objs/client.o

objs/server.o: objs server.c
	$(CC) $(CFLAGS) -c server.c -o objs/server.o

clean:
	rm -f client server objs/*.o
	$(MAKE) -C libft clean

fclean: clean
	rm -rf objs
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re objs