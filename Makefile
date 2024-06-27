# Variable definition
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INCDIR) -Iutil_funcs/Libft

SERVER_NAME = server
CLIENT_NAME = client
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = util_funcs/Libft
LDFLAGS = -L$(LIBFTDIR) -lft

.SILENT:

SERVER_SRC = $(wildcard $(SRCDIR)/server/*.c)
CLIENT_SRC = $(wildcard $(SRCDIR)/client/*.c)



all: $(SERVER_NAME) $(CLIENT_NAME)
OBJDIR = obj

LIBFT = $(LIBFTDIR)/libft.a


SRC = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/*.c, $(OBJDIR)/%.o, $(SRC))


server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

all: server client

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
