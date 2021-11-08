NAME = prog
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -MMD -MP
-include $(depends)
depends = $(objs:.o=.d)

srcs = tests.cpp Account.cpp
objs = $(srcs:.cpp=.o)

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
