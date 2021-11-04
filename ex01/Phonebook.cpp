#include "Contact.hpp"
#include "Phonebook.hpp"
#include "Color.hpp"
#include <iomanip>

static bool isNumber(const std::string& str)
{
    return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

static void printColor(const char *style, const char *str)
{
    std::cout << '\n'
                << style
                << str
                << '\n'
                << std::endl
                << END;
}

void Phonebook::exit()
{
    std::exit(0);
}

void Phonebook::addItem(int i, void (Contact::*fn)(std::string), std::string s)
{
    std::string line;

    std::cout << s;
    if (!std::getline(std::cin, line))
        exit();
    while (line.empty())
    {
        std::cout << RED BOLD << s << END;
        if (!std::getline(std::cin, line))
            exit();
    }
    (this->contact[i].*fn)(line);
}

void Phonebook::add(int i)
{
    this->addItem(i, &Contact::setFirstName ,    "first name     : ");
    this->addItem(i, &Contact::setLastName ,     "last name      : ");
    this->addItem(i, &Contact::setNickname ,     "nickname       : ");
    this->addItem(i, &Contact::setphoneNumber ,  "phone number   : ");
    this->addItem(i, &Contact::setDarkestSecret ,"darkest secret : ");
}

void Phonebook::printItem(std::string s)
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

void Phonebook::printContact(std::string s1, std::string s2)
{
    std::cout << UNDERLINE
              << s1
              << s2
              << std::endl
              << END;
}

void Phonebook::printContacts(int i)
{
    this->printContact("first name     : ", contact[i].getFirstName());
    this->printContact("last name      : ", contact[i].getLastName());
    this->printContact("nickname       : ", contact[i].getNickname());
    this->printContact("phone number   : ", contact[i].getPhoneNumber());
    this->printContact("darkest secret : ", contact[i].getDarkestSecret());
    std::cout << std::endl;
}

void Phonebook::search()
{
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
        this->printItem(std::to_string(i));
        this->printItem(contact[i].getFirstName());
        this->printItem(contact[i].getLastName());
        this->printItem(contact[i].getNickname());
        std::cout << "|"
                  << std::endl;
    }
    printColor(BLUE UNDERLINE, "PLEASE INPUT INDEX");
    std::string input;
    if (!std::getline(std::cin, input))
        exit();
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
    printContacts(index);
}
