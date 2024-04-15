# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 19:28:28 by gdel-val          #+#    #+#              #
#    Updated: 2024/04/03 19:28:29 by gdel-val         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
C = gcc
FLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
RM = rm -rf

SRC	=	main.c		\
		plot.c		\


LIBFT_DIR = libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR) --silent
	@gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(LIBFT_A)
	@make -C $(LIBFT_DIR) clean --silent

fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re:	fclean
	@make all
	
.PHONY:	all clean fclean re