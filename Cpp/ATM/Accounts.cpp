#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int ID;
    string Password;
    string Name;
    string Email;
    string PersonID;
    double Balance;
    double Loan;

public:
    Account() {
        static int NID = 10000;
        NID++;
        ID = NID;
        Balance = 0;
        Loan = 0;
    }

    double GetBalance () {
        return Balance;
    }

    double GetLoan () {
        return Loan;
    }

    string GetPersonID () {
        return PersonID;
    }

    string GetEmail () {
        return Email;
    }

    string GetName () {
        return Name;
    }

    int GetID () {
        return ID;
    }


    void Deposit (double money) {
        Balance += money;
        return;
    }

    virtual bool Withdraw (double money) {
        if (money > Balance)
            return 0;
        Balance -= money;
        return 1;
    }

    bool Login (string Nam, string Passwor) {
        if (Nam == Name && Passwor == Password)
            return 1;
        return 0;
    }

    void RequestLoan (double money) {
        Loan += money;
        Balance += money;
        return;
    }

    bool PayLoan (double money) {
        if (Balance < money)
            return 0;
        if (money > Loan)
            return 0;
        Balance -= money;
        Loan -= money;
        return 1;
    }
};

class SavingAccount : public Account {
public:
    SavingAccount () {
    }

    SavingAccount (string nam, string passwor, string perid, string emai) {
        Name = nam;
        Password = passwor;
        PersonID = perid;
        Email = emai;
    }
};

class CreditAccount : public Account {
private:
    double Credit;

public:
    CreditAccount () {
    }

    void SetCredit (double num) {
        Credit = num;
    }

    double GetCredit () {
        return Credit;
    }

    CreditAccount (string nam, string passwor, string perid, string emai) {
        Name = nam;
        Password = passwor;
        PersonID = perid;
        Email = emai;
        Credit = 0;
    }

    bool Withdraw (double money) {
        if (Balance + Credit < money)
            return 0;
        Balance -= money;
        return 1;
    }
};