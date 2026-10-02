#ifndef ROOM_H
#define ROOM_H
#include <string>
class Room {
    private:
        std::string roomNumber;
        std::string roomType;
        double price=0.0;
        bool isAvailable=true;
    public:
        Room(std::string number, std::string type, double rentalPrice,bool availability);
        std::string getRoomNumber();
        std::string getRoomType();
        double getPrice();
        bool getAvailability();
        void setAvailability(bool availability);

        std::string toCSV() const;
        void fromCSV(const std::string& csv);
};
#endif