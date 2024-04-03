#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    void deposit();

    void withdraw();
    void getBalance();
    void getInterestRate();
    void setInterestRate();
    void getAccountNumber();





    BankAccount(int accountNumber, double balance, double interestRate) {

        this->accountNumber = accountNumber;
        this->balance = 0;
        this->interestRate = 0;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
    
};

    void BankAccount::deposit() {
        cout << "Введите номер счета: ";
        cin >> this->accountNumber;
        cout << "Внесите деньги: ";
        cin >> this->balance;
        cout << "счет открыт!!!" << endl << endl;
    }

    void BankAccount::withdraw() {
        
        long long int s;
        
        do {
            cout << "Сколько желаете снять";
            cin >> s;
            if (s > this->balance) cout << "" << endl;
           
        } while (s > this->balance);
        this->balance -= s;
        cout << "Деньги успешно сняты" << endl;
        

    }
    
    void BankAccount::getBalance() {

        cout << endl << "Текущий :" << endl;
        cout << " Номер" << this->accountNumber << endl;
        cout << "кол-вщ средств на счете" << this->balance << endl;
    }

    void BankAccount::getInterestRate() {

        double m = 1.0 / 12;
        cout << "ваша проц ставка пока ноль. введите ставку" << endl;
        cin >> this->interestRate;
        double i = this->balance * this->interestRate * m;
        cout << "Теперь вы в год получаете" << i << endl;
    }

    void BankAccount::setInterestRate() {

        double s = 1.0 / 12;
        int b = 5;
        this->interestRate = this->balance * b * s;
        cout << "Ваша процентная ставка обновлена до 5 " << this->interestRate << endl;
    }

    void BankAccount::getAccountNumber() {

        cout << "Номер вашей банковской карты" << this->accountNumber << endl;
    }

    bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Перевод выполнен" << endl;
            return true;
        }
        else (from.balance < amount); {
            cout << "Много" << endl;
            return true;
        }
    }

    int main() {
        int choice;
        BankAccount account(123456789, 1000, 0);

        
            cout << "Выберите операцию:" << endl;
            cout << "1. Внести средства на счет" << endl;
            cout << "2. Снять средства со счета" << endl;
            cout << "3. Получить текущий баланс" << endl;
            cout << "4. Установить процентную ставку" << endl;
            cout << "5. Получить процентную ставку" << endl;
            cout << "6. Получить номер счета" << endl;
            cout << "7. Перевести средства на другой счет" << endl;
            cout << "8. Выход" << endl;
            cout << "Выберите операцию (1-8): ";
            cin >> choice;

            switch (choice) {
            case 1: {
                account.deposit();
                break;
            }
            case 2: {
                account.withdraw();
                break;
            }
            case 3: {
                account.getBalance();
                break;
            }
            case 4: {
                account.setInterestRate();
                break;
            }
            case 5: {
                account.getInterestRate();
                break;
            }
            case 6: {
                account.getAccountNumber();
                break;
            }
            
            
            default: {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
            }
            }
         
        
    }
    

