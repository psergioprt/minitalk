CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INCDIR) -Iutil_funcs/Libft -Iutil_funcs/ft_printf

SERVER_NAME = server
CLIENT_NAME = client
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = util_funcs/Libft
FT_PRINTF_DIR = util_funcs/ft_printf

LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# .SILENT:

SERVER_SRC = $(wildcard $(SRCDIR)/server*.c)
CLIENT_SRC = $(wildcard $(SRCDIR)/client*.c)
ERRORS_FUNC_SRC = $(wildcard $(SRCDIR)/errors_output_funcs.c)

SERVER_OBJS = $(patsubst $(SRCDIR)/%.c, %.o, $(SERVER_SRC))
CLIENT_OBJS = $(patsubst $(SRCDIR)/%.c, %.o, $(CLIENT_SRC))
ERRORS_FUNC_OBJS = $(patsubst $(SRCDIR)/%.c, %.o, $(ERRORS_FUNC_SRC))

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF) $(ERRORS_FUNC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF) $(ERRORS_FUNC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

%.o: $(SRCDIR)/%.c $(wildcard $(INCDIR)/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(RM) -f *.o
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) -f $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all libft clean fclean re
deploy:
