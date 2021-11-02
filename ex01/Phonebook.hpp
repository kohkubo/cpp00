#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook
{
public:
    void add(int i);
    void search();
    void exit();
private:
    void printItem(std::string s);
    void printContacts(int i);
    void printContact(std::string s, std::string t);
    void addItem(int i, void (Contact::*fn)(std::string), std::string s);
    Contact contact[8];
};

#endif
