#ifndef INVOICE_H
#define INVOICE_H
#include <string>
class Invoice {
    
    private:
        std::string invoiceID;
        std::string customerCccd;
        std::string employeeCccd;
        std::string roomNumber;
        std::string checkInDate;
        std::string checkOutDate;
        double totalAmount=0.0;
    public:
        Invoice()= default;
        Invoice(const std::string &invoiceID, const std::string &customerCccd, const std::string &employeeCccd,
                const std::string &roomNumber, const std::string &checkInDate, const std::string &checkOutDate, double totalAmount);
        ~Invoice()=default;

        std::string getInvoiceID() const;
        void setInvoiceID(const std::string& invoiceID);

        std::string getCustomerCccd() const;
        void setCustomerCccd(const std::string& customerCccd);

        std::string getEmployeeCccd() const;
        void setEmployeeCccd(const std::string& employeeCccd);

        std::string getRoomNumber() const;
        void setRoomNumber(const std::string& roomNumber);

        std::string getCheckInDate() const;
        void setCheckInDate(const std::string& checkInDate);

        std::string getCheckOutDate() const;
        void setCheckOutDate(const std::string& checkOutDate);

        double getTotalAmount() const;
        void setTotalAmount(double totalAmount);

        std::string toCSV() const;
        void fromCSV(const std::string& csv);
}; 
#endif