#include "Contact.hpp"

void setFirstName(std::string s) { this->firstName = s; }
void setLastName(std::string s) { this->lastName = s; }
void setNickname(std::string s) { this->nickname = s; }
void setphoneNumber(std::string s) { this->phoneNumber = s; }
void setDarkestSecret(std::string s) { darkestSecret = s; }
std::string getFirstName() const { return firstName; }
std::string getLastName() const { return lastName; }
std::string getNickname() const { return nickname; }
std::string getPhoneNumber() const { return phoneNumber; }
std::string getDarkestSecret() const { return darkestSecret; }
