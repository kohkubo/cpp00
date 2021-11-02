#include <iostream>

void megaphone(const std::string &s) {
    std::string d;
    std::transform(s.begin(), s.end(), d.begin(), toupper);
    std::cout << d;
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        megaphone(av[i]);
    }
    std::cout << std::endl;
    return 0;
}
