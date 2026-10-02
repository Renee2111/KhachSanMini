#include "customer.h"
#include <sstream>

Customer::Customer(const std::string &cccd, const std::string &name, const std::string &phone, const std::string &email, const std::string &customerType, const std::string &birthdate, const std::string &address)
    : Person(cccd, name, phone, email), customerType(customerType), birthdate(birthdate), address(address) {}

std::string Customer::getCustomerType() const {
    return customerType;
}
void Customer::setCustomerType(const std::string& customerType) {
    this->customerType = customerType;
}

std::string Customer::getBirthdate() const {
    return birthdate;
}
void Customer::setBirthdate(const std::string& birthdate) {
    this->birthdate = birthdate;
}

std::string Customer::getAddress() const {
    return address;
}
void Customer::setAddress(const std::string& address) {
    this->address = address;
}

std::string Customer::toCSV() const {
    std::ostringstream oss;
    
    oss << cccd << "," << name << "," << phone << "," << email << ","<< customerType << "," << birthdate << "," << address;
    return oss.str();
}

void Customer::fromCSV(const std::string &line) {
    std::stringstream ss(line);
    std::getline(ss, cccd, ',');
    std::getline(ss, name, ',');
    std::getline(ss, phone, ',');
    std::getline(ss, email, ',');
    std::getline(ss, customerType, ',');
    std::getline(ss, birthdate, ',');
    std::getline(ss, address, ',');
}
