#ifndef AUTHLOGIN_H
#define AUTHLOGIN_H

#include <string>
#include <vector>
#include "../../model/Account/account.h"

class AuthLogin {
    private:
        std::vector<Account> accounts;
        std::string filename;
    public:
        AuthLogin(const std::string& filename="data/accounts.txt");
        
        void loadAccounts();
        void saveAccounts();

        bool login(const std::string& username, const std::string& password, int& role, std::string& cccd);
        bool registerAccount(const std::string& username, const std::string& password, int role=2, const std::string& cccd="");
        bool changePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword);
        bool forgotPassword(const std::string& username, const std::string& cccd, const std::string& newPassword);

        bool toStaff(const std::string& username);
        Account* getAccountByUsername(const std::string& username);
        bool AccountExists(const std::string& username);
        std::vector<Account> getCustomerAccounts() const;
};
#endif