NAME	=	minishell

# Libraries and Headers
LIBFT	= ./libft/libft.a
HEADERS	= -I includes -I libft/HEADERS

# Configuration
CC		= 	cc
CFLAGS	=	-g3
# CFLAGS	+= -fsanitize=address -g
RM 		= rm -rf

# Readline files
LFLAGS	= -L $(HOME)/.brew/Cellar/readline/8.2.1/lib -lreadline
IFLAGS	= -I includes -I $(HOME)/.brew/Cellar/readline/8.2.1/include

# Source Files
SRC =	./src/main.c \
				./src/environment/env.c \
				./src/nodes/nodes.c \
				./src/utils/free_and_error.c\
				./src/utils/utils.c \
				./src/utils/syntax_check.c \
				./src/tokenize/lexer.c \
				./src/tokenize/quotes.c \
				./src/tokenize/tokenize_utils.c \
				./src/tokenize/tokenizer.c \
				./src/expanding/expander.c \
				./src/expanding/expand_dollar.c \
				./src/expanding/expand_double_dollar.c \
				./src/expanding/expander_utils.c \
				./src/expanding/expand_exit_and_empty.c \
				./src/expanding/quote_concatenation.c \
				./src/commands/build_commands.c \
				./src/commands/build_inits_and_nodes.c \
				./src/commands/build_redirections.c \
				./src/commands/build_utils.c \
				./src/expanding_heredoc/heredoc_expanding.c \
				./src/expanding_heredoc/heredoc_dollar.c \
				./src/expanding_heredoc/heredoc_pid.c \
				./src/utils/testing.c

# Object files and directories
# obj folder in src?: src/obj 
OBJ 	= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))
OBJDIR	= obj

# ANSI escape colors for messages


# Objectives
all: $(LIBFT) $(OBJDIR) $(NAME)
	@echo "Compilation Done"

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s -C ./libft

# Object files
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: ./src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/environment/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/nodes/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/tokenize/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/expanding/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/commands/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/expandig_heredoc/&.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJDIR)/%.o: ./src/utils/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

# Cleaning
clean:
	@$(MAKE) -s clean -C ./libft
	@$(RM) $(OBJ)
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s fclean -C ./libft
	@rmdir  $(OBJDIR)
	@echo "Cleaned executor"

re: fclean all

.PHONY: all libft clean fclean re
