#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string username;
    std::string password;
    int role;
    std::string cccd;

public:
    static constexpr int ADMIN = 0;
    static constexpr int EMPLOYEE = 1;
    static constexpr int CUSTOMER = 2;

    Account() = default;
    Account(const std::string& username,
            const std::string& password,
            int role,
            const std::string& cccd);

    std::string getUsername() const;
    void setUsername(const std::string& username);

    std::string getPassword() const;
    void setPassword(const std::string& password);

    int getRole() const;
    void setRole(int role);

    std::string getCccd() const;
    void setCccd(const std::string& cccd);

    std::string toCSV() const;
    void fromCSV(const std::string& line);
};
#endif