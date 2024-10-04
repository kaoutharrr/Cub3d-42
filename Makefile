# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 19:45:30 by kkouaz            #+#    #+#              #
#    Updated: 2023/08/19 05:59:39 by adihaj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -I/usr/include -Imlx_linux -O3 
CC = clang

NAME = cub3D

SRC =	gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		gnl/ft_strjoin.c \
		parsing/parse_settings.c \
		parsing/settings_checker.c \
		parsing/cub.c \
		parsing/check_utils.c \
		parsing/utils.c \
		parsing/for_norm.c \
		parsing/map_check.c \
		parsing/parse_utils.c \
		parsing/utils2.c \
		raycasting/main.c\
		raycasting/game.c\
		raycasting/init.c\
		raycasting/tools.c\
		raycasting/moves.c \
		raycasting/rays.c\
		raycasting/3d.c \
		raycasting/hooks.c \
		raycasting/rotate.c \
		raycasting/texture.c



OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	@make -C ./libft


$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz   libft/libft.a -o $(NAME)



clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
