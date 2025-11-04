# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 17:10:30 by pbret             #+#    #+#              #
#    Updated: 2025/11/04 19:34:26 by pbret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= greatJob
OBJ_DIR 	= obj_$(NAME)
SRCS		= tests.cpp \
			Account.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Werror -Wextra -std=c++98 #-ggdb #-Wconversion -MMD

$(OBJ_DIR)/%.o : %.cpp
			@mkdir -p $(@D)
			@$(CC) -g $(CFLAGS) -c $< -o $@
			
all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) -g 
			@echo "\033[32m""Compilation of $(NAME) completed!""\033[0m"

clean:
			@$(RM) $(OBJ_DIR)
			@echo "\033[36m""Directory $(OBJ_DIR) delected.""\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[36m""Directory $(NAME) delected.""\033[0m"

re:			fclean 	all

.PHONY: all clean fclean re
