#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
public:
	~BankAccount();

	BankAccount(const BankAccount& other);

	BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

	BankAccount(std::string accNum, std::string holderName)
		: accountNumber(accNum), accountHolderName(holderName), balance(0.0) {
	}

	// Getters
	std::string getAccountNumber() const;
	std::string getAccountHolderName() const;
	double getBalance() const;

	// Equality operator: compares account numbers (AI Assisted)
	bool operator==(const BankAccount& other) const;

	// Less-than operator: compares balances (AI Assisted)
	bool operator<(const BankAccount& other) const;

	// Greater-than operator: compares balances (AI Assisted)
	bool operator>(const BankAccount& other) const;

	void setAccountHolderName(std::string holderName);

	// Add these operator overloads as member functions inside the BankAccount class declaration
	BankAccount& operator+=(double amount);
	BankAccount& operator-=(double amount);
};

// Function declaration for createAccountFromInput
BankAccount createAccountFromInput();

// Prints the details of a BankAccount object
inline void printAccount(const BankAccount& account)
{
	std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
	std::cout << "Account Holder: " << account.getAccountHolderName() << std::endl;
	std::cout << "Balance: $" << account.getBalance() << std::endl;
}

// Finds a BankAccount in the vector by account number and returns a pointer, or nullptr if not found
inline BankAccount* findAccount(std::vector<BankAccount>& accounts, const std::string& accNum)
{
	for (auto& account : accounts)
	{
		if (account.getAccountNumber() == accNum)
		{
			return &account;
		}
	}
	return nullptr;
}

#endif