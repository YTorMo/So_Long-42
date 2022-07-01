# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yago_42 <Yago_42@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 09:28:41 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/06/29 11:23:54 by Yago_42          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -w -Wunreachable-code -Ofast
LIBMLX	= ./lib/MLX42_
LIBFT	= ./lib/libft
USER	= ytoro-mo

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw -L /usr/local/Cellar/glfw/3.3.7/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

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

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft