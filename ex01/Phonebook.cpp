#include "Contact.hpp"
#include "Phonebook.hpp"
#include "Color.hpp"
#include <iomanip>

namespace {
    bool isNumber(const std::string& str)
    {
        return str.find_first_not_of( "0123456789" ) == std::string::npos;
    }

    void printColor(const char *style, const char *str)
    {
        std::cout << '\n'
                    << style
                    << str
                    << '\n'
                    << std::endl
                    << END;
    }

    void printItem(const std::string &s)
    {
        std::cout << UNDERLINE
                << "|";
        std::cout << " ";
        if (s.size() > 10)
            std::cout << s.substr(0, 9) + ".";
        else
            std::cout << std::right << std::setw(10) << s;
        std::cout << " "
                << END;
    }

    void printContact(const std::string s1, const std::string s2)
    {
        std::cout << UNDERLINE
                << s1
                << s2
                << std::endl
                << END;
    }
}

Phonebook::Phonebook(void)
{
    unsigned int i = 0;

    try {
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
                return ;
            else if (input == "ADD")
                Phonebook::add(i++ % 8);
            else if (input == "SEARCH")
                Phonebook::search();
        }
    } catch (std::exception &e) {
        std::cerr << "Error" << std::endl;
    }
}

Phonebook::~Phonebook(void)
{
    std::cout << "see you!" << std::endl;
}

void Phonebook::addItem(int i, void (Contact::*fn)(std::string), const std::string &s)
{
    std::string line;

    std::cout << s;
    if (!std::getline(std::cin, line))
        throw std::exception();
    while (line.empty())
    {
        std::cout << RED BOLD << s << END;
        if (!std::getline(std::cin, line))
            throw std::exception();
    }
    (this->contact[i].*fn)(line);
}

void Phonebook::add(int i)
{
    this->addItem(i, &Contact::setFirstName,    "first name     : ");
    this->addItem(i, &Contact::setLastName,     "last name      : ");
    this->addItem(i, &Contact::setNickname,     "nickname       : ");
    this->addItem(i, &Contact::setphoneNumber,  "phone number   : ");
    this->addItem(i, &Contact::setDarkestSecret,"darkest secret : ");
}

void Phonebook::printContacts(int i) const
{
    printContact("first name     : ", contact[i].getFirstName());
    printContact("last name      : ", contact[i].getLastName());
    printContact("nickname       : ", contact[i].getNickname());
    printContact("phone number   : ", contact[i].getPhoneNumber());
    printContact("darkest secret : ", contact[i].getDarkestSecret());
    std::cout << std::endl;
}

void Phonebook::search() const
{
    if (contact[0].getFirstName() == "")
        return ;
    std::cout << GREEN UNDERLINE
              << "                                                     "
              << '\n'
              << "|   INDEX    | FIRST NAME | LAST NAME  | NICK NAME  |"
              << std::endl
              << END;
    for (size_t i = 0; i < 8; i++)
    {
        if (contact[i].getFirstName() == "")
            break ;
        printItem(std::to_string(i));
        printItem(contact[i].getFirstName());
        printItem(contact[i].getLastName());
        printItem(contact[i].getNickname());
        std::cout << "|"
                  << std::endl;
    }
    printColor(BLUE UNDERLINE, "PLEASE INPUT INDEX");
    std::string input;
    if (!std::getline(std::cin, input))
        throw std::exception();
    int index;
    if (input.empty() || isNumber(input) == false || !(std::istringstream(input) >> index))
    {
        printColor(RED BOLD, "INVALID INDEX");
        return ;
    }
    if (index < 0 || index > 7 || contact[index].getFirstName() == "")
    {
        printColor(RED BOLD, "INDEX OUT OF RANGE");
        return ;
    }
    this->printContacts(index);
}


