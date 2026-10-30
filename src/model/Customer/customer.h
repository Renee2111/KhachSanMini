#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "model/Person/person.h"

class Customer : public Person {
    private:
        std::string customerType;
        std::string birthdate;
        std::string address;
    public:
        Customer() = default;
        Customer(const std::string &cccd, const std::string &name, const std::string &phone, const std::string &email, const std::string &customerType, const std::string &birthdate, const std::string &address    );
        ~Customer() = default;

        std::string getCustomerType() const;
        void setCustomerType(const std::string& customerType);
    
        std::string getBirthdate() const;
        void setBirthdate(const std::string& birthdate);

        std::string getAddress() const;
        void setAddress(const std::string& address);

        std::string toCSV() const override;
        void fromCSV(const std::string& csv) override;
};
#endif 