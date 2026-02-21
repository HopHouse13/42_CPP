# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 16:59:56 by pbret             #+#    #+#              #
#    Updated: 2026/02/21 14:36:54 by pbret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Span
OBJ_DIR 	= obj_$(NAME)
SRCS		= main.cpp \
			Span.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
CC			= c++
RM			= rm -rf	
CFLAGS		= -Wall -Werror -Wextra -std=c++98 #-Wconversion -Iincludes -MMD -ggdb

$(OBJ_DIR)/%.o : %.cpp
			@mkdir -p $(@D)
			@$(CC) -g $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -g 
			@echo "\033[32m""Compilation of $(NAME) completed!""\033[0m"

clean:
			@$(RM) $(OBJ_DIR)
			@echo "\033[36m""Directory $(OBJ_DIR) delected.""\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[36m""Directory $(NAME) delected.""\033[0m"

re:			fclean 	all

.PHONY: all clean fclean re