#include "person.h"

Person::Person(const std::string &cccd, const std::string &name, const std::string &phone, const std::string &email)
    : cccd(cccd), name(name), phone(phone), email(email) {}

std::string Person::getCccd() const {
    return cccd;
}
void Person::setCccd(const std::string& cccd) {
    this->cccd = cccd;
}

std::string Person::getName() const {
    return name;
}
void Person::setName(const std::string& name) {
    this->name = name;
}

std::string Person::getPhone() const {
    return phone;
}
void Person::setPhone(const std::string& phone) {
    this->phone = phone;
}

std::string Person::getEmail() const {
    return email;
}
void Person::setEmail(const std::string& email) {
    this->email = email;
}