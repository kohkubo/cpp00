#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook
{
public:
    Phonebook(void);
    ~Phonebook(void);
private:
    void add(int i);
    void search() const;
    void printContacts(int i) const;
    void addItem(int i, void (Contact::*fn)(std::string), const std::string &s);
    Contact contact[8];
};

#endif
