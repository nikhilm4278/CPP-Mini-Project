#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    unsigned int accNo;
    string name;
    double balance;

public:
    BankAccount(string accountName, unsigned int accountNumber, double initialBalance):
        name(accountName),
        accNo(accountNumber)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            cout << "Invalid Amount\n";
            balance = 0;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    void display()
    {
        cout << "Account: " << name << "\nAccount " <<  accNo <<"\nBalance: Rs. " << balance << endl ;
    }
};

int main()
{
    string name;
    double initialDeposit;
    unsigned int accountNumber;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

    cout << "Enter accountNumber: ";
    cin >> accountNumber;

    BankAccount account(name, accountNumber, initialDeposit);

    int choice;
    double amount;

    do
    {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}