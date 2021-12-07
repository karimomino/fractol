# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:14:04 by kamin             #+#    #+#              #
#    Updated: 2021/12/07 23:30:42 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = fractol

FLAGS = -Wall -Wextra -Werror -g3 -O2

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADER = includes

SOURCES = ft_fractol.c \
			ft_screen.c \
			ft_img.c \
			ft_math.c \
			ft_util.c \
			ft_hooks.c \
			ft_errors.c \
			

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(SRCS) $(FLAGS) -I $(HEADER) libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -Ofast -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_fractol.h
	@mkdir -p obj
	@$(C) $(FLAGS) -Imlx -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean re norme all clean