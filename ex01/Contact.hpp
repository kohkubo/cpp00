#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>

class Contact
{
public:
    void setFirstName(std::string s) { firstName = s; }
    void setLastName(std::string s) { lastName = s; }
    void setNickname(std::string s) { nickname = s; }
    void setphoneNumber(std::string s) { phoneNumber = s; }
    void setDarkestSecret(std::string s) { darkestSecret = s; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif
