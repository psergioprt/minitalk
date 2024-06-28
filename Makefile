CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INCDIR) -Iutil_funcs/Libft

SERVER_NAME = server
CLIENT_NAME = client
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = util_funcs/Libft

# LDFLAGS = -L$(LIBFTDIR)
LIBFT = $(LIBFTDIR)/libft.a

# .SILENT:

#SERVER_SRC = $(wildcard $(SRCDIR)/server.c)
#CLIENT_SRC = $(wildcard $(SRCDIR)/client.c)

SERVER_SRC = $(wildcard $(SRCDIR)/server/*.c)
CLIENT_SRC = $(wildcard $(SRCDIR)/client/*.c)

#SERVER_OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SERVER_SRC))
#CLIENT_OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(CLIENT_SRC))


SERVER_OBJS = $(patsubst $(SRCDIR)/server/%.c, $(OBJDIR)/server/%.o, $(SERVER_SRC))
CLIENT_OBJS = $(patsubst $(SRCDIR)/client/%.c, $(OBJDIR)/client/%.o, $(CLIENT_SRC))


all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)


$(OBJDIR)/server/%.o: $(SRCDIR)/server/%.c $(wildcard $(INCDIR)/*.h)
	@echo "creating obj directory if not exists..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/client/%.o: $(SRCDIR)/client/%.c $(wildcard $(INCDIR)/*.h)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) -f $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all libft clean fclean re
deploy:
