#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>

class Contact
{
public:
    void setFirstName(const std::string s);
    void setLastName(const std::string s);
    void setNickname(const std::string s);
    void setphoneNumber(const std::string s);
    void setDarkestSecret(const std::string s);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif
