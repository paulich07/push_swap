# === Colors ===
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m
BOLD		= \033[1m
UNDERLINE = \033[4;32m
GREEN_BG = \033[42m

NAME					= push_swap
BONUS_NAME		= checker

HEADERS_DIR				= include
SRC_DIR						= src
OBJ_DIR						= obj
LIBFT_DIR					= libs/libft
GET_NEXT_LINE_DIR = libs/get_next_line

CC 						=	cc
CFLAGS 				= -Wall -Werror -Wextra -I$(HEADERS_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(GET_NEXT_LINE_DIR)
LDFLAGS 			= -L$(LIBFT_DIR) -lft
LIBFT					= $(LIBFT_DIR)/libft.a

LIBFT_CLEAN_ENABLED ?= 1

SRCS = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations2.c \
		$(SRC_DIR)/operations_helper.c \
		$(SRC_DIR)/algorithms.c \
		$(SRC_DIR)/algorithms2.c \
		$(SRC_DIR)/algorithms3.c \
		$(SRC_DIR)/algorithms3_helper.c

SRCS_BONUS = \
		$(SRC_DIR)/checker.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations2.c \
		$(SRC_DIR)/algorithms3.c \

SRCS_GET_NEXT_LINE = \
		$(GET_NEXT_LINE_DIR)/get_next_line.c \
		$(GET_NEXT_LINE_DIR)/get_next_line_utils.c \

OBJS								= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS					= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
GET_NEXT_LINE_OBJS	= $(SRCS_GET_NEXT_LINE:$(GET_NEXT_LINE_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)---- Building of $(NAME) ----$(RESET)";

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(CYAN)---- Linking target $@ $(RESET)---- using $^"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(GET_NEXT_LINE_OBJS) $(LIBFT)
	@echo "$(CYAN)---- Linking target: $@ $(RESET)---- using $^"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(GET_NEXT_LINE_OBJS) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)---- Building of $(BONUS_NAME)$(RESET)"

$(LIBFT):
	@echo "$(BLUE)---- Building libft$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GET_NEXT_LINE_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(MAGENTA)---- Create folder $@ $(RESET)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)---- Removing .o files in $(NAME)----$(RESET)"
	@rm -rf $(OBJ_DIR)
ifeq ($(LIBFT_CLEAN_ENABLED),1)
		@$(MAKE) clean -C $(LIBFT_DIR) --silent
endif

fclean:
	@$(MAKE) --no-print-directory LIBFT_CLEAN_ENABLED=0 clean
	@if [ -n "$(NAME)" ] && [ -e "$(NAME)" ]; then \
		echo "$(RED)---- Removing executable $(NAME)...$(RESET)"; \
		rm -f $(NAME); \
	fi
	@if [ -n "$(BONUS_NAME)" ] && [ -e "$(BONUS_NAME)" ]; then \
		echo "$(RED)---- Removing bonus executable: $(BONUS_NAME)$(RESET)"; \
		rm -f $(BONUS_NAME); \
	fi
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re bonus