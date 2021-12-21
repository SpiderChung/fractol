# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2021/12/18 16:27:44 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADERS = ./headers/

SRC = fractol.c frac_utils.c frac_errors.c celtic_mandelbrot.c mandelbrot.c julia.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

FOREIGN_TARGETS = libft/libft.a

%.o: %.c
	$(CC) -I $(HEADERS) -Imlx -c $< -o $@

all: lftm $(NAME) 

$(NAME): $(OBJ) $(FOREIGN_TARGETS) 
	@$(CC) -I $(HEADERS) $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework OpenCL -framework AppKit -Llibft -lft -o $(NAME)
	@echo "[INFO] Fractol [$(NAME)] created"

$(FOREIGN_TARGETS):
	@$(MAKE) -C $(dir $@) $(notdir $@)

lftm:
	@$(MAKE) -C $(dir $(FOREIGN_TARGETS))

clean:
	@$(REMOVE) $(OBJ)
	@echo "[INFO] Removed objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Fractol and objects removed "

re: fclean all

.PHONY: all clean fclean re 