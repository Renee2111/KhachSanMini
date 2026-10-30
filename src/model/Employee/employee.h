#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "model/Person/person.h"

class Employee : public Person {
    private:
        std::string position;
        double salary=0.0;
    public:
        Employee()= default;
        Employee(const std::string &cccd, const std::string &name, const std::string &phone, const std::string &email,
                 const std::string &position, double salary);
        ~Employee()=default;

        std::string getPosition() const;
        void setPosition(const std::string& position);

        double getSalary() const;
        void setSalary(double salary);

        std::string toCSV() const override;
        void fromCSV(const std::string& csv) override;
};
#endif 