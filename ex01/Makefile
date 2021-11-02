NAME = phonebook
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98 -pedantic -fsanitize=integer -fsanitize=address -fsanitize=leak

srcs = main.cpp phonebook.cpp

all: $(NAME)

$(NAME): $(srcs)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(srcs)

clean:
	@$(RM) -rf $(objs)
	@$(RM) -rf *.dSYM

fclean:
	@$(RM) -rf $(NAME) $(objs)
	@$(RM) -rf *.dSYM

re: fclean all

PHONY: all clean fclean re
