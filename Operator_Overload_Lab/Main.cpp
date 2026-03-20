#include <iostream>
#include <vector>
#include <string>
#include "Data.h"

int main() {
	std::vector<BankAccount> accounts;
	int choice;
	std::string accNum, holderName;
	double amount;

	while (true) {
		std::cout << "Bank Account Management System Menu:\n"
			<< "1. Create New Account\n"
			<< "2. Deposit Funds\n"
			<< "3. Withdraw Funds\n"
			<< "4. View All Accounts\n"
			<< "5. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
		}

		switch (choice) {
		case 1: {
			BankAccount newAccount = createAccountFromInput();
			std::cout << "Account created successfully\n\n";
			accounts.push_back(newAccount);
			break;
		}
		case 2: {
			std::cout << "\nEnter account number to deposit into: ";
			std::cin >> accNum;
			BankAccount* account = findAccount(accounts, accNum);
			if (account) {
				std::cout << "Enter amount to deposit: $";
				std::cin >> amount;
				account->operator+=(amount);
			}
			else {
				std::cout << "Account not found.\n\n";
			}
			break;
		}
		case 3: {
			std::cout << "\nEnter account number to withdraw from: ";
			std::cin >> accNum;
			BankAccount* account = findAccount(accounts, accNum);
			if (account) {
				std::cout << "Enter amount to withdraw: $";
				std::cin >> amount;
				account->operator-=(amount);
			}
			else {
				std::cout << "Account not found.\n\n";
			}
			break;
		}
		case 4: {
			std::cout << "\n--- All Accounts ---\n";
			for (const auto& acc : accounts) {
				std::cout << "Acc Number: " << acc.getAccountNumber()
					<< ", Holder: " << acc.getAccountHolderName()
					<< ", Balance: $" << acc.getBalance() << std::endl;
			}
			std::cout << "-------------------\n\n";
			break;
		}
		case 5:
			std::cout << "\nExit program. Goodbye!\n";
			return 0;
		default:
			std::cout << "Invalid choice. Please try again.\n\n";
		}
	}
}