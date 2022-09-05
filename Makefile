# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 09:28:41 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/09/05 09:36:11 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -w -Wunreachable-code -Ofast
LIB_A	= ./lib
USER	= ytoro-mo
GLFW	= /System/Volumes/Data/sgoinfre/goinfre/Perso/ytoro-mo/homebrew/Cellar/glfw/3.3.8/lib

HEADERS	= -I ./include
LIBS	= -lglfw -L $(GLFW) $(LIB_A)/libmlx42.a $(LIB_A)/libft.a
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

#/usr/local/Cellar/glfw/3.3.7/lib/ 

BOLD	= \033[1m
BLACK	= \033[30;1m
RED	= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft