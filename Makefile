# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 15:16:54 by lbrandy           #+#    #+#              #
#    Updated: 2021/11/13 15:25:27 by lbrandy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Imlx
CC = gcc
LIB = libmlx.dylib
LIBFT_DIR = ./source/libft/
LIBFT = ./source/libft/libft.a
SRCS = argv_check.c ft_pars_all.c main.c mlx_help.c \
		pars_file.c pars_map_copy_mainmap.c pars_map_flood.c \
		pars_map_part_2.c pars_map.c texture_reading.c \
		error_handler.c pars_utils.c
OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME):$(OBJDIR) $(OBJS) so_long.h
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -Lmlx -lmx -framework OpenGL -framework Appkit $(LIB) $(LIBFT) $(SRCS) -o $(NAME)
$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
