#include <iostream>

void megaphone(const char *s) {
    std::string d(s);
    std::transform(d.begin(), d.end(), d.begin(), toupper);
    std::cout << d;
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        if (i != 1)
            std::cout << ' ';
        megaphone(av[i]);
    }
    std::cout << std::endl;
    return 0;
}
