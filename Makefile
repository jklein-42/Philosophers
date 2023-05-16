# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 19:02:43 by jklein            #+#    #+#              #
#    Updated: 2023/02/27 11:38:27 by jklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = srcs
OBJ_DIR = .objs

#***************************************************#
#					DIRECTORIES						#
#***************************************************#

SRC =	$(SRC_DIR)/ft_controll.c \
		$(SRC_DIR)/ft_handle_err.c \
		$(SRC_DIR)/ft_handle_fork.c \
		$(SRC_DIR)/ft_handle_philo.c \
		$(SRC_DIR)/ft_handle_thread.c \
		$(SRC_DIR)/ft_handle_time.c \
		$(SRC_DIR)/ft_main.c \
		$(SRC_DIR)/ft_thread_Mutx.c \
		$(SRC_DIR)/ft_utils.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

#***************************************************#
#                   FLAGS                           #
#***************************************************#

CC = clang
HEAD = -I./headers
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -pthread
RM = /bin/rm -rf

#***************************************************#
#                   COMMANDS                        #
#***************************************************#

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[2;18;5;199EExecuting object files\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects files\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving philo\033[0m"

re: fclean all

PHONY: all clean fclean re
