#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    protected:
        std::string cccd;
        std::string name;
        std::string phone;
        std::string email;
    public:
        Person()= default;
        Person(const std::string &cccd, const std::string &name, const std::string &phone, const std::string &email);
        virtual ~Person()=default;

        std::string getCccd() const;
        void setCccd(const std::string& cccd);

        std::string getName() const;
        void setName(const std::string& name);

        std::string getPhone() const;
        void setPhone(const std::string& phone);

        std::string getEmail() const;
        void setEmail(const std::string& email);

        virtual std::string toCSV() const=0;
        virtual void fromCSV(const std::string& csv)=0;
        
};
#endif
