#include <iostream>
#include "Phonebook.hpp"
#include "Color.hpp"

int main()
{
    Phonebook book;
    unsigned int i = 0;

    while (1)
    {
        std::string input;
        std::cout << '\n'
                  << BLUE UNDERLINE
                  << "Enter a command: ADD, SEARCH, EXIT"
                  << '\n'
                  << std::endl
                  << END;
        if (!std::getline(std::cin, input))
            break ;
        if (input == "EXIT")
            book.exit();
        else if (input == "ADD")
            book.add(i++ % 8);
        else if (input == "SEARCH")
            book.search();
    }
    return 0;
}
