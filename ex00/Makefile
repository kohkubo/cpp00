NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=undefined -fsanitize=leak

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

PHONY: all clean fclean re
