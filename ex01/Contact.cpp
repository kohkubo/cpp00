#include "Contact.hpp"

void Contact::setFirstName(const std::string s) { this->firstName = s; }
void Contact::setLastName(const std::string s) { this->lastName = s; }
void Contact::setNickname(const std::string s) { this->nickname = s; }
void Contact::setphoneNumber(const std::string s) { this->phoneNumber = s; }
void Contact::setDarkestSecret(const std::string s) { this->darkestSecret = s; }
const std::string &Contact::getFirstName() const { return this->firstName; }
const std::string &Contact::getLastName() const { return this->lastName; }
const std::string &Contact::getNickname() const { return this->nickname; }
const std::string &Contact::getPhoneNumber() const { return this->phoneNumber; }
const std::string &Contact::getDarkestSecret() const { return this->darkestSecret; }
