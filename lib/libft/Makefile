# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:17:15 by ytoro-mo          #+#    #+#              #
#    Updated: 2022/09/15 10:49:06 by ytoro-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_M =	$(shell find ./src -iname "*.c")

FILES_B =	$(shell find ./bonus -iname "*.c")

NAME = libft.a

GCC = gcc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

HEADERS = -I ./

OBJS_DIR = ./
#OBJ_M = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_M)))
OBJ_M = ${FILES_M:.c=.o}
OBJ_B = ${FILES_B:.c=.o}

BOLD	= \033[1m
GREEN	= \033[32;1m
RESET	= \033[0m

%.o: %.c
	@$(GCC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "${GREEN}$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME):	$(OBJ_M)
			${AR} ${NAME} ${OBJ_M}

all:		${NAME}

bonus:		${OBJ_B}
			${AR} ${NAME} ${OBJ_B}

clean:
			${RM} ${OBJ_M} ${OBJ_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re