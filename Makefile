# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 09:28:41 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/09/12 11:28:11 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -w -Wunreachable-code -Ofast -g
LIB_A	= ./lib
USER	= ytoro-mo
GLFW	= /System/Volumes/Data/sgoinfre/goinfre/Perso/ytoro-mo/homebrew/Cellar/glfw/3.3.8/lib

HEADERS	= -I ./includes
LIBS	= -lglfw -L $(GLFW) $(LIB_A)/libmlx42.a $(LIB_A)/libft.a
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}


BOLD	= \033[1m
GREEN	= \033[32;1m
RESET	= \033[0m

# //= Recipes =//

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "${GREEN}$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft