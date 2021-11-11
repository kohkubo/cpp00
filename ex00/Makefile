NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -MMD -MP

srcs = megaphone.cpp
objs = $(srcs:.cpp=.o)
depends = $(objs:.o=.d)
-include $(depends)

.PHONY: all
all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(objs)

.PHONY: clean
clean:
	$(RM) -rf *.dSYM
	$(RM) -rf $(objs) $(depends)

.PHONY: fclean
fclean: clean
	$(RM) -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re
