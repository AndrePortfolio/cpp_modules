NAME = aForm
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
COMPRESS = ar rcs
RM = rm -rf

OBJ_DIR = objects
SRC_DIR = sources
S = main Bureaucrat AForm PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm
SRC = $(addprefix $(SRC_DIR)/,$(addsuffix .cpp, $(S)))
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.cpp=.o)))

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
