# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcheung <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 11:10:05 by kcheung           #+#    #+#              #
#    Updated: 2017/05/13 23:21:44 by kcheung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./srcs/
SRC_NAME = main.c \
		   asm_strcmp.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_NAME:%.c=%.o))

INC_DIR = ./includes/
INC = -I$(INC_DIR)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: obj $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@chmod 755 $@

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [$(NAME)] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@echo "Delete" [$(NAME)] "..." $(OK)
	@echo "Delete" [$(NAME_C)] "..." $(OK)
re: fclean all

.PHONY: all, clean, fclean, re
