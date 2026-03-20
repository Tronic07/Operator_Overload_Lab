#include <iostream>
#include <string>
#include <vector>
#include "Data.h"

BankAccount::~BankAccount() {
    // No dynamic memory to free, so leave empty
}
BankAccount::BankAccount(const BankAccount& other)
    : accountNumber(other.accountNumber),
    accountHolderName(other.accountHolderName),
    balance(other.balance) {
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

void BankAccount::setAccountHolderName(std::string holderName) {
    accountHolderName = holderName;
}

BankAccount createAccountFromInput() {
    std::string accNum, holderName;

    std::cout << "\nEnter account number: ";
    std::cin >> accNum;
    std::cout << "Enter account holder name (use underscores for space, e.g., John_Doe): ";
    std::cin >> holderName;

    return BankAccount(accNum, holderName);
}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << "\n" << std::endl;
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n" << std::endl;
    }
    else if (amount > balance) {
        std::cout << "Insufficient funds.\n";
    }
    else {
        std::cout << "Invalid withdrawal amount.\n";
    }
    return *this;
}
