#include "authlogin.h"

#include <fstream>
#include <stdexcept>

namespace {
    bool isValidRole(int role) {
        return role == Account::ADMIN ||
            role == Account::EMPLOYEE ||
            role == Account::CUSTOMER;
    }

    bool isValidField(const std::string& value) {
        return value.find_first_of(",\r\n") == std::string::npos;
    }

    Account parseAccount(const std::string& line, std::size_t lineNumber) {
        const std::size_t firstComma = line.find(',');
        if (firstComma == std::string::npos) {
            throw std::runtime_error(
                "Invalid account record at line " + std::to_string(lineNumber));
        }
        const std::size_t secondComma = line.find(',', firstComma + 1);
        if (secondComma == std::string::npos) {
            throw std::runtime_error(
                "Invalid account record at line " + std::to_string(lineNumber));
        }
        const std::size_t thirdComma = line.find(',', secondComma + 1);
        if (thirdComma == std::string::npos ||
            line.find(',', thirdComma + 1) != std::string::npos) {
            throw std::runtime_error(
                "Invalid account record at line " + std::to_string(lineNumber));
        }

        const std::string username = line.substr(0, firstComma);
        const std::string password =
            line.substr(firstComma + 1, secondComma - firstComma - 1);
        const std::string roleText =
            line.substr(secondComma + 1, thirdComma - secondComma - 1);
        const std::string cccd = line.substr(thirdComma + 1);
        std::size_t parsedLength = 0;
        int role = 0;
        try {
            role = std::stoi(roleText, &parsedLength);
        } catch (const std::exception&) {
            throw std::runtime_error(
                "Invalid role at line " + std::to_string(lineNumber));
        }

        if (parsedLength != roleText.size() || !isValidRole(role)) {
            throw std::runtime_error(
                "Invalid role at line " + std::to_string(lineNumber));
        }

        return Account(username, password, role, cccd);
    }
}

AuthLogin::AuthLogin(const std::string& filename) : filename(filename) {
    loadAccounts();
}

void AuthLogin::loadAccounts() {
    accounts.clear();
    std::ifstream input(filename + "accounts.txt");
    if (!input.is_open()) {
        throw std::runtime_error("Unable to open account file: " + filename);
    }

    std::vector<Account> loadedAccounts;
    std::string line;
    std::size_t lineNumber = 0;
    while (std::getline(input, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }
        loadedAccounts.push_back(parseAccount(line, lineNumber));
    }

    if (input.bad()) {
        throw std::runtime_error("Error reading account file: " + filename);
    }

    accounts.swap(loadedAccounts);
}

void AuthLogin::saveAccounts() {
    std::ofstream output(filename + "accounts.txt", std::ios::trunc);
    if (!output.is_open()) {
        throw std::runtime_error("Unable to open account file for writing: " + filename);
    }

    for (const Account& acc : accounts) {
        output << acc.toCSV() << '\n';
    }
    if (!output) {
        throw std::runtime_error("Error writing account file: " + filename);
    }
    output.close();
}

bool AuthLogin::login(const std::string& username,
                      const std::string& password,
                      int& role,
                      std::string& cccd) {
    Account* account = getAccountByUsername(username);
    if (account == nullptr || account->getPassword() != password) {
        return false;
    }

    role = account->getRole();
    cccd = account->getCccd();
    return true;
}

bool AuthLogin::registerAccount(const std::string& username,
                               const std::string& password,
                               int role,
                               const std::string& cccd) {
    if (username.empty() || password.empty() ||
        !isValidField(username) || !isValidField(password) ||
        !isValidField(cccd) || !isValidRole(role) ||
        AccountExists(username)) {
        return false;
    }

    accounts.emplace_back(username, password, role, cccd);
    try {
        saveAccounts();
    } catch (...) {
        accounts.pop_back();
        throw;
    }
    return true;
}

bool AuthLogin::changePassword(const std::string& username,
                               const std::string& oldPassword,
                               const std::string& newPassword) {
    Account* account = getAccountByUsername(username);
    if (account == nullptr || account->getPassword() != oldPassword ||
        newPassword.empty() || !isValidField(newPassword)) {
        return false;
    }

    const std::string previousPassword = account->getPassword();
    account->setPassword(newPassword);
    try {
        saveAccounts();
    } catch (...) {
        account->setPassword(previousPassword);
        throw;
    }
    return true;
}

bool AuthLogin::forgotPassword(const std::string& username,
                               const std::string& cccd,
                               const std::string& newPassword) {
    Account* account = getAccountByUsername(username);
    if (account == nullptr || account->getCccd() != cccd ||
        newPassword.empty() || !isValidField(newPassword)) {
        return false;
    }

    const std::string previousPassword = account->getPassword();
    account->setPassword(newPassword);
    try {
        saveAccounts();
    } catch (...) {
        account->setPassword(previousPassword);
        throw;
    }
    return true;
}

bool AuthLogin::toStaff(const std::string& username) {
    Account* account = getAccountByUsername(username);
    if (account == nullptr || account->getRole() != Account::CUSTOMER) {
        return false;
    }

    account->setRole(Account::EMPLOYEE);
    try {
        saveAccounts();
    } catch (...) {
        account->setRole(Account::CUSTOMER);
        throw;
    }
    return true;
}

Account* AuthLogin::getAccountByUsername(const std::string& username) {
    for (Account& account : accounts) {
        if (account.getUsername() == username) {
            return &account;
        }
    }
    return nullptr;
}

bool AuthLogin::AccountExists(const std::string& username) {
    return getAccountByUsername(username) != nullptr;
}

std::vector<Account> AuthLogin::getCustomerAccounts() const {
    std::vector<Account> customerAccounts;
    for (const Account& account : accounts) {
        if (account.getRole() == Account::CUSTOMER) {
            customerAccounts.push_back(account);
        }
    }
    return customerAccounts;
}