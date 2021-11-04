NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

srcs = megaphone.cpp

all: $(NAME)

$(NAME): $(srcs)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(srcs)

clean:
	@$(RM) -rf # $(objs)
	@$(RM) -rf *.dSYM

fclean:
	@$(RM) -rf $(NAME) # $(objs)
	@$(RM) -rf *.dSYM

re: fclean all

debug: $(srcs)
	$(CXX) $(CXXFLAGS) -g -fsanitize=integer -fsanitize=address -fsanitize=leak -o $(NAME) $(srcs)

PHONY: all clean fclean re
