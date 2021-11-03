#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>

class Contact
{
public:
    void setFirstName(std::string s);
    void setLastName(std::string s);
    void setNickname(std::string s);
    void setphoneNumber(std::string s);
    void setDarkestSecret(std::string s);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif
