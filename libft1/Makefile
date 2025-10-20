NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra  -Werror -g3

INC_DIR = includes/
SRC_DIR = srcs/
OBJS_DIR = objs/

CTYPES_FILES =	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c

GNL_FILES = 	get_next_line.c\
				get_next_line_bonus.c

LISTS_FILES = 	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

MEMORY_FILES = 	ft_bzero.c \
				ft_calloc.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_free_split.c\
				ft_freenull_split.c

PRINTF_FILES = 	ft_printf.c \
				ft_utils.c

STDIO_FILES = 	ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c

STDLIB_FILES = 	ft_atoi.c \
				ft_itoa.c

STRING_FILES = 	ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c

SRCS = 	$(addprefix $(SRC_DIR)/ctypes/, $(CTYPES_FILES)) \
		$(addprefix $(SRC_DIR)/gnl/, $(GNL_FILES)) \
		$(addprefix $(SRC_DIR)/lists/, $(LISTS_FILES)) \
		$(addprefix $(SRC_DIR)/memory/, $(MEMORY_FILES)) \
		$(addprefix $(SRC_DIR)/printf/, $(PRINTF_FILES)) \
		$(addprefix $(SRC_DIR)/stdio/, $(STDIO_FILES)) \
		$(addprefix $(SRC_DIR)/stdlib/, $(STDLIB_FILES)) \
		$(addprefix $(SRC_DIR)/string/, $(STRING_FILES))

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "$(YELLOW)A linkar $(NAME)... $(DEF_COLOR)"
	@sh -c 'i=0; while [ $$i -lt 10 ]; do \
		echo -n "\b|"; sleep 0.05; \
		echo -n "\b/"; sleep 0.05; \
		echo -n "\b-"; sleep 0.05; \
		echo -n "\b\\"; sleep 0.05; \
		i=$$(($$i+1)); \
	done'
	@echo "\b\b$(GREEN)OK!$(DEF_COLOR)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) criado com sucesso!$(DEF_COLOR)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus