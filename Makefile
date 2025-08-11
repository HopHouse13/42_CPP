GREEN	= \033[1;32m
RED		= \033[0;31m
BLUE	= \033[0;34m
YELLOW	= \033[1;33m
CYAN	= \033[0;36m
RESET	= \033[0m

NAME		= 	PmergeMe

CPP			= 	c++

FLAGS		= 	-Wall -Werror -Wextra -Wconversion -std=c++98 -g3 -MMD

SRC_FILES	=	main				\
				PmergeMe			\

SRC_DIR		= 	./

OBJ_DIR		= 	./obj/

SRC			= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))

OBJ			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

DEP			= 	$(OBJ:.o=.d)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(RESET)"

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Done$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME) executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Done$(RESET)"

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)