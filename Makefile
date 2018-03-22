NAME = fillit

CFLAGS = -Wall -Wextra -Werror

CC = gcc

INCLUDES_PATH = includes/

SRCS_NAME = main.c \
			can_place.c \
			check_piece.c \
			format_piece.c \
			parser.c \
			solve.c \
			solve_func.c \

SRCS = $(SRCS_NAME)

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
