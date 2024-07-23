# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 19:28:28 by gdel-val          #+#    #+#              #
#    Updated: 2024/07/03 22:45:15 by gdel-val         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

HEADERS = include
SRC_DIR = src

SRC	=	main.c		\
		plot.c		\
		utils.c		\
		utils2.c	\
		fractal.c	\
		zoom.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
DEBUG = -g -fsanitize=address
RM = rm -rf

LIBFT_DIR = libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR) --silent
	@make -C minilibx-linux
	@gcc $(FLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(LIBFT_A)
	@make -C $(LIBFT_DIR) clean --silent

fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

norme:
	norminette ./$(HEADERS) ./$(SRC_DIR)

re:	fclean
	@make all
	
.PHONY:	all clean fclean norme re
