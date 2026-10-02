#include "invoice.h"
#include <sstream>
#include <string>
#include <fstream>
#include <limits>

Invoice::Invoice(const std::string &invoiceID, const std::string &customerCccd, const std::string &employeeCccd,
                 const std::string &roomNumber, const std::string &checkInDate, const std::string &checkOutDate, double totalAmount)
    : invoiceID(invoiceID), customerCccd(customerCccd), employeeCccd(employeeCccd),
      roomNumber(roomNumber), checkInDate(checkInDate), checkOutDate(checkOutDate), totalAmount(totalAmount) {}
std::string Invoice::getInvoiceID() const {
    return invoiceID;
}
void Invoice::setInvoiceID(const std::string& invoiceID) {
    this->invoiceID = invoiceID;
}

std::string Invoice::getCustomerCccd() const {
    return customerCccd;
}
void Invoice::setCustomerCccd(const std::string& customerCccd) {
    this->customerCccd = customerCccd;
}

std::string Invoice::getEmployeeCccd() const {
    return employeeCccd;
}
void Invoice::setEmployeeCccd(const std::string& employeeCccd) {
    this->employeeCccd = employeeCccd;
}

std::string Invoice::getRoomNumber() const {
    return roomNumber;
}
void Invoice::setRoomNumber(const std::string& roomNumber) {
    this->roomNumber = roomNumber;
}

std::string Invoice::getCheckInDate() const {
    return checkInDate;
}
void Invoice::setCheckInDate(const std::string& checkInDate) {
    this->checkInDate = checkInDate;
}

std::string Invoice::getCheckOutDate() const {
    return checkOutDate;
}
void Invoice::setCheckOutDate(const std::string& checkOutDate) {
    this->checkOutDate = checkOutDate;
}

double Invoice::getTotalAmount() const {
    return totalAmount;
}
void Invoice::setTotalAmount(double totalAmount) {
    this->totalAmount = totalAmount;
}

std::string Invoice::toCSV() const {
    std::ostringstream oss;
    oss << invoiceID << "," << customerCccd << "," << employeeCccd << ","
        << roomNumber << "," << checkInDate << "," << checkOutDate << ","
        << totalAmount;
    return oss.str();
}
void Invoice::fromCSV(const std::string &line) {
    std::stringstream ss(line);
    std::string totalAmountStr;
    std::getline(ss, invoiceID, ',');
    std::getline(ss, customerCccd, ',');
    std::getline(ss, employeeCccd, ',');
    std::getline(ss, roomNumber, ',');
    std::getline(ss, checkInDate, ',');
    std::getline(ss, checkOutDate, ',');
    std::getline(ss, totalAmountStr, ',');

    try {
        totalAmount = std::stod(totalAmountStr);
    } 
    catch (...) {
        totalAmount = 0.0;
    }
}