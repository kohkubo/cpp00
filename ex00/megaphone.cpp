#include <iostream>

void megaphone(char *s) {
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
        i++;
    }
    std::cout << s;
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; ++i) {
        megaphone(av[i]);
    }
    std::cout << std::endl;
    return 0;
}
