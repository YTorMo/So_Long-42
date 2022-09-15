# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 09:28:41 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/09/15 11:23:44 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -Ofast -g -Wall -Werror -Wextra
LIB_A	= ./lib
USER	= ytoro-mo
GLFW	= /System/Volumes/Data/sgoinfre/goinfre/Perso/ytoro-mo/homebrew/Cellar/glfw/3.3.8/lib

HEADERS	= -I ./includes
LIBS	= -lglfw -L $(GLFW) $(LIB_A)/libmlx42.a ./lib/libft/libft.a
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}


BOLD	= \033[1m
GREEN	= \033[32;1m
RESET	= \033[0m

all: $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "${GREEN}$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@make re -C ./lib/libft && make libclean && gcc $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)

libclean:
	@make clean -C ./lib/libft

fclean: clean
	@rm -f $(NAME) && make fclean -C ./lib/libft

re: clean all

.PHONY: all, clean, fclean, re, libclean
