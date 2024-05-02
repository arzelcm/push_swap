# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 11:50:28 by arcanava          #+#    #+#              #
#    Updated: 2024/05/02 22:57:38 by arcanava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#----COLORS----#
DEF_COLOR = \033[1;39m
WHITE_BOLD = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#----COMPILER----#
CC = cc
CCFLAGS = -Wall -Werror -Wextra

#----DIRS----#
BIN_DIR = bin/
INC_DIR = inc/
SRCS_DIR = src/
INCLUDES = -I$(INC_DIR) 

#----LIBFT----#
LIBFT_DIR = lib/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDES += -I$(LIBFT_DIR) 

#----MANDATORY----#
SRCS =	push_swap.c \
		utils.c \
		stack.c \
		safe_utils.c \
		swap.c \
		push.c \
		rotate.c \
		rev_rotate.c \
		node.c \
		radix.c
OBJS = $(SRCS:%.c=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)

#----BONUS----#
BSRCS = pipex_bonus.c \
		utils_bonus.c \
		safe_utils_bonus.c \
		initiators_bonus.c
BOBJS = $(BSRCS:%.c=$(BIN_DIR)%.o)
BDEPS = $(BOBJS:%.o=%.d)

#----DEBUG----#
ifdef DEBUG
	OBJS = $(SRCS:%.c=$(BIN_DIR)%_debug.o)
	BOBJS = $(BSRCS:%.c=$(BIN_DIR)%_debug.o)
	NAME = $(DEBUG_NAME)
endif

#----OS COMPATIBILITY----#
ifneq ($(OS),Windows_NT)
	UNAME_S = $(shell uname -s)
else
	UNAME_S = Windows
endif

#----RULES----#
all:
	@$(MAKE) --no-print-directory make_libft
	@$(MAKE) --no-print-directory $(NAME)

ifndef BONUS
$(NAME): $(LIBFT_LIB) $(OBJS)
	@printf "$(BLUE)Linking objects and creating program...$(DEF_COLOR)\n"
	@$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)[✓] $(PINK)$(NAME)$(GREEN) created!!!$(DEF_COLOR)"
else
$(NAME): $(LIBFT_LIB) $(BOBJS)
	@echo "$(BLUE)\nLinking objects and creating binary program...$(DEF_COLOR)"
	@$(CC) $(CCFLAGS) $(BOBJS) $(LIBFT_LIB) $(DARWIN_FLAGS) -o $(NAME)
	@echo "$(GREEN)[✓] $(PINK)$(NAME) Bonus$(GREEN) created!!!$(DEF_COLOR)"
endif

ifndef DEBUG
$(BIN_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@printf "$(CIAN)Compiling: $(PINK)$(notdir $<)...$(DEF_COLOR)\n"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CCFLAGS) $(INCLUDES) -MMD -c $< -o $@
else
$(BIN_DIR)%_debug.o: $(SRCS_DIR)%.c Makefile
	@printf "$(CIAN)Compiling: $(PINK)$(notdir $<)...$(DEF_COLOR)\n"
	@mkdir -p $(BIN_DIR)
	@$(CC) -g $(CCFLAGS) $(INCLUDES) -MMD -c $< -o $@
endif

clean:	libft_clean
	@rm -rf $(BIN_DIR)
	@echo "$(RED)bin/ deleted$(DEF_COLOR)"

fclean: libft_fclean clean
	@rm -rf $(NAME)
	@echo "$(RED)Executable deleted$(DEF_COLOR)\n"

re: fclean all

b: bonus

bonusre: fclean bonus

make_libft:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus
	@echo ""

libft_clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

libft_fclean:
	@echo "$(RED)Cleaning $(PINK)Libft$(RED)...$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

norme:
	@echo "$(YELLOW)\n------------------------\nChecking norme errors...\n------------------------\n$(DEF_COLOR)"
	@-norminette $(INC_DIR) $(SRCS_DIR)
	@echo ""

n: norme

.PHONY: all \
		clean \
		fclean \
		re \
		bonus \
		bonusre \
		make_libft \
		libft_clean \
		libft_fclean \
		norme \
		b \

-include $(DEPS)
-include $(BDEPS)

.SILENT:
