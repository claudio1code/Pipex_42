NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra  -Werror -g3

INC_DIR = includes/
SRC_DIR = srcs/
OBJS_DIR = objs/
LIBFT_DIR = libft/

SRCS_LIST = pipex.c utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(INCS_DIR) -I $(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft

GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)A linkar $(NAME)... $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(CYAN)A compilar $<... $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re