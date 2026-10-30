#include "room.h"
#include<sstream>
#include<string>
#include<fstream>

Room::Room(std::string number, std::string type, double rentalPrice,bool availability)
    : roomNumber(number), roomType(type), price(rentalPrice), isAvailable(availability) {}
std::string Room::getRoomNumber() {
    return roomNumber;
}
void Room::setAvailability(bool availability) {
    isAvailable = availability;
}

std::string Room::getRoomType() {
    return roomType;
}

double Room::getPrice() {
    return price;
}

bool Room::getAvailability() {
    return isAvailable;
}
void Room::setAvailability(bool availability) {
    isAvailable = availability;
}

std::string Room::toCSV() const {
    std::ostringstream oss;
    oss << roomNumber << "," << roomType << "," << price << "," << isAvailable;
    return oss.str();
}

void Room::fromCSV(const std::string &line) {
    std::stringstream ss(line);
    std::getline(ss, roomNumber, ',');
    std::getline(ss, roomType, ',');
    std::string priceStr;
    std::getline(ss, priceStr, ',');
    price = std::stod(priceStr);
    std::string availabilityStr;
    std::getline(ss, availabilityStr, ',');
    try {
        price = std::stod(priceStr);
    } 
    catch (...) {
        price = 0.0;
    }

    isAvailable = (availabilityStr == "1" || availabilityStr == "true");
}
