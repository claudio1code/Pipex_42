NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

# -- Caminhos definidos diretamente --
SRCS	= srcs/pipex.c srcs/utils.c
OBJS	= objs/pipex.o objs/utils.o

# -- Flags de compilação --
INC		= -I includes/ -I libft/includes
LIBS	= -L libft/ -lft

# ------------------------------------

all: lib-compile $(NAME)

# Regra para compilar a libft primeiro
lib-compile:
	@make -sC libft/

$(NAME): $(OBJS)
	@echo "A linkar $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Pipex compilado!"

# Regra de padrão explícita
objs/%.o: srcs/%.c
	@mkdir -p objs
	@echo "A compilar $<..."
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf objs
	@make -sC libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -sC libft/ fclean

re: fclean all

.PHONY: all clean fclean re lib-compile