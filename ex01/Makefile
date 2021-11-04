NAME = phonebook
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

srcs = main.cpp Phonebook.cpp Contact.cpp

.PHONY: all
all: $(NAME)

$(NAME): $(srcs)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(srcs)

.PHONY: clean
clean:
	@$(RM) -rf *.dSYM

.PHONY: fclean
fclean:
	@$(RM) -rf $(NAME)
	@$(RM) -rf *.dSYM

.PHONY: re
re: fclean all

.PHONY: debug
debug: $(srcs)
	$(CXX) $(CXXFLAGS) -g -fsanitize=integer -fsanitize=address -fsanitize=leak -o $(NAME) $(srcs)
