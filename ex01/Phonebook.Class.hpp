#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.Class.hpp"

class Phonebook
{
public:
    void addItem(int i, void (Contact::*fn)(std::string), std::string s);
    void printItem(std::string s);
    void add(int i);
    void search();
    void exit();
    void printContacts(int i);
    void printContact(std::string s, std::string t);
private:
    Contact contact[8];
};

#endif
