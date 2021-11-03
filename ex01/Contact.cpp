#include "Contact.hpp"

void Contact::setFirstName(std::string s) { this->firstName = s; }
void Contact::setLastName(std::string s) { this->lastName = s; }
void Contact::setNickname(std::string s) { this->nickname = s; }
void Contact::setphoneNumber(std::string s) { this->phoneNumber = s; }
void Contact::setDarkestSecret(std::string s) { darkestSecret = s; }
std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickname() { return this->nickname; }
std::string Contact::getPhoneNumber() { return this->phoneNumber; }
std::string Contact::getDarkestSecret() { return this->darkestSecret; }
