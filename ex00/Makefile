NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra

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
