#include <iostream>
#include <limits>
#include <cassert>


void ignoreLine () {

    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}
namespace Bank {
   constexpr double startingBalance = 100;
}

void checkBalance (double balance) {
    std::cout <<"Your balance is " <<balance << std::endl;
}

double depositCoins (double balance) {
    while (true) {
        double deposit;
        std::cout <<" Amount to deposit: ";
        std::cin >> deposit;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Please enter a number. \n";
            continue;
        }

        ignoreLine();

        if (deposit < 1 || deposit > 1000) {
           std::cout << "Amount must be between 1 and 1000.\n";
            continue;
        }
        balance += deposit;
        std::cout << "Your balance is " << balance << " coins.\n";
        return balance;
    }
}

double withdrawCoins (double balance) {
    while (true) {
        double withdraw;
        std::cout<< "Amount to withdraw: ";
        std::cin >> withdraw;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Please enter a number. \n";
            continue;
        }
        ignoreLine();

        if (withdraw <= 0) {
            std::cout << "Amount must be positive.\n";
            continue;
        }
        if (withdraw > balance) {
            std::cout << "Insufficient balance. You have "
              << balance << " coins.\n";
            continue;

        }
       balance -= withdraw;
        std::cout << "Withdrawal successful. Your balance is "
            << balance << " coins.\n";
        return balance;
    }
}


void displayMenu () {
    int option = 0;
    double balance = Bank::startingBalance;
    do {
        std::cout <<" \n \n 1. Check balance \n "
        "2. Deposit coins \n "
        "3. Withdraw coins \n "
        "4. Exit \n "
        "Choose an option: ";
        std::cin >> option;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Please enter a number. \n";
            continue;
        }

        ignoreLine();

        switch (option) {
            case 1:std::cout <<" 1. Check balance \n ";  checkBalance(balance);
                break;
            case 2:std::cout <<" 2. Deposit \n ";balance = depositCoins(balance);
                break;
            case 3:std::cout <<" 3. Withdraw \n "; balance = withdrawCoins(balance);
                break;
            case 4:std::cout <<" 4. Exit\n"
                "Your final balance is : "<<balance;
                std::cout<< "\n Goodbye! \n";
                break;
            default:std::cout <<" Invalid option \n";
        }
    assert ( balance >= 0);
    }
    while (option!=4);

}

int main () {
    displayMenu ();
}
