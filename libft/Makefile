# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#*   Updated: 2017/09/18 11:58:20 by thuynh           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_ = ft_
FILES = bzero memalloc memccpy memchr memcmp memcpy memdel memmove memset \
		putchar putchars putchar_fd putendl putendl_fd putnbr putnbr_fd \
		putstr putstr_fd puterror putnull \
		strcat strccount strccountto strchr strclr strcmp strcpy strctrim \
		strdel strdeltwo strdelthree strdup strdupuntil strdupfrom strequ \
		strfindnreplace strfsub strfremalloc strfresize striter \
		striteri strjoin strfjoin strffjoin strlcat strlen \
		strmap strmapi strncat strncmp strncpy strnequ strnew strnstr strrchr \
		strrev strsplit strsplits strstr strsub strtrim strremove \
		arraynew arraynew4d arraylen arraydel wtoi strwtoi \
		lstadd lstdel lstdelone lstiter lstmap lstnew \
		isalnum isalpha isascii isdigit islower isprint isupper iswhitespace \
		swap tolower toupper strtolower strtoupper itoa itoa_base atoi \
		setnull setdoubletozero setunsignedinttozero setunsignedshorttozero \
		abs sign rgb_to_hex shade_colour percentof powerof

FUNCS = $(addprefix $(FT_), $(FILES))

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNCS))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(C_NAM:.c=.o)
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

H_LOC = -I inc

C_FLAGS = -Wall -Wextra -Werror

RED = [31m
GREEN = [32m
BLUE = [34m
YELLOW = [33m
MAGENTA = [35m
GREY = [37m
GREEN_LIGHT = [92m
YELLOW_LIGHT = [93m
YELLOW_BOLD = [1;33m
MAGENTA_LIGHT = [95m
BLINK = [5m
END_COLOUR = \033[0m

all: $(NAME)

$(NAME): $(O_SRC) obj/get_next_line.o
	@printf "$(YELLOW_LIGHT)\nBuilding $@...$(END_COLOUR)"
	@ar rcs $@ $(O_SRC) obj/get_next_line.o
	@echo "$(GREEN) Library Complete!$(END_COLOUR)"

$(O_LOC)%.o: $(C_LOC)%.c
	@gcc $(C_FLAGS) $(H_LOC) -o $@ -c $<
	@printf "$(RED)*$(END_COLOUR)"

clean:
	@/bin/rm -rf $(O_SRC)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
