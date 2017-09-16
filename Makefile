# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#*   Updated: 2017/09/13 17:13:55 by thuynh           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

FILES = server_side load check unload hash_function
FILES2 = client_side

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

C_LOC2 = src2/
C_NAM2 = $(addsuffix .c, $(FILES2))
C_SRC2 = $(addprefix $(C_LOC2), $(C_NAM2))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

O_LOC2 = obj2/
O_NAM2 = $(addsuffix .o, $(FILES2))
O_SRC2 = $(addprefix $(O_LOC2), $(O_NAM2))

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOCS = -I inc -I libft/inc
HEADERS = inc/server.h inc/database.h libft/inc/libft.h

C_FLAGS = -Wall -Wextra -Werror

TEST_MAIN = main_for_testing.c

RED = [31m
GREEN = [32m
BLUE = [34m
YELLOW = [33m
MAGENTA = [35m
GREY = [37m
GREEN_LIGHT = [92m
GREEN_LIGHT_BLINK = [5;92m
YELLOW_LIGHT = [93m
YELLOW_BOLD = [1;33m
YELLOW_LIGHT_BOLD = [1;93m
MAGENTA_LIGHT = [95m
BLINK = [5m
END_COLOUR = \033[0m

all: $(NAME) $(NAME2)

$(NAME): $(O_SRC) $(LIB_SRC)
	@echo "$(YELLOW_BOLD)Compiling executable... $@$(END_COLOUR)"
	@gcc $(C_FLAGS) $^ -lpthread -o $@

$(NAME2): $(O_SRC2) $(LIB_SRC)
	@echo "$(YELLOW_BOLD)Compiling executable... $@$(END_COLOUR)"
	@gcc $(C_FLAGS) $^ -lpthread -o $@

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS)
	@echo "$(GREY)Re-compiling src file... $(END_COLOUR)$(YELLOW)$<$(END_COLOUR)"
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

$(O_LOC2)%.o: $(C_LOC2)%.c $(HEADERS)
	@echo "$(GREY)Re-compiling src file... $(END_COLOUR)$(YELLOW)$<$(END_COLOUR)"
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

$(LIB_SRC): force
	@echo "$(YELLOW)----------- Checking Libft Library -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C $(LIB_LOC)
	@echo "$(YELLOW)----------- Library Check Complete -----------$(END_COLOUR)"

force:
	@true

clean:
	@/bin/rm -rf $(O_SRC)
	@/bin/rm -rf $(O_SRC2)
	@make clean -C $(LIB_LOC)
	@echo "$(GREEN)clean complete!$(END_COLOUR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME2)
	@make fclean -C $(LIB_LOC)
	@echo "$(GREEN)fclean complete!$(END_COLOUR)"

re: fclean all

test: $(NAME)
	@./$(NAME)

.PHONY: all test force clean fclean re
