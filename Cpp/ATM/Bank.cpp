#include "Accounts.cpp"
#include <vector>

class Bank {
private:
    int SAN, CAN, AN;
    vector<CreditAccount> CA;
    vector<SavingAccount> SA;

public:
    Bank() {
        SAN = 0;
        CAN = 0;
        AN = 0;
        CA.clear();
        SA.clear();
        memset(NumTable, 0, sizeof(NumTable));
    }

    int NumTable[10000][2];

    int Res (int type, string name, string password, string perid, string email) {
        ++AN;
        NumTable[AN][0] = type;
        if (type == 0) {
            NumTable[AN][1] = SAN;
            SavingAccount tmp(name, password, perid, email);
            SA.push_back(tmp);
            ++SAN;
        } else {
            NumTable[AN][1] = CAN;
            CreditAccount tmp(name, password, perid, email);
            CA.push_back(tmp);
            ++CAN;
        }
        return AN;
    }

    int Login(string name, string password) {
        for (int i = 1; i <= AN; ++i) {
            int tmp = NumTable[i][1];
            if (NumTable[i][0] == 1) {
                if (CA[tmp].Login(name, password))
                    return i;
            } else {
                if (SA[tmp].Login(name,password))
                    return i;
            }
        }
        return 0;
    }

    bool Withdraw(int id, double money) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].Withdraw(money);
        else
            return SA[tmp].Withdraw(money);
    }

    void Deposit(int id, double money) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            CA[tmp].Deposit(money);
        else
            SA[tmp].Deposit(money);
    }

    bool Transfer(int id1, int id2, double money) {
        if (Withdraw(id1, money)) {
            Deposit(id2, money);
            return 1;
        }
        return 0;
    }

    bool PayLoan(int id, double money) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].PayLoan(money);
        else
            return SA[tmp].PayLoan(money);
    }

    void RequestLoan(int id, double money) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            CA[tmp].RequestLoan(money);
        else
            SA[tmp].RequestLoan(money);
    }

    double GetBalance(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetBalance();
        else
            return SA[tmp].GetBalance();
    }

    double GetLoan(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetLoan();
        else
            return SA[tmp].GetLoan();
    }


    string GetPersonID(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetPersonID();
        else
            return SA[tmp].GetPersonID();
    }
    
    string GetEmail(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetEmail();
        else
            return SA[tmp].GetEmail();
    }

    string GetName(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetName();
        else
            return SA[tmp].GetName();
    }
    
    bool SetCredit(int id, double money) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1) {
            CA[tmp].SetCredit(money);
            return 1;
        }
        return 0;
    }
    
    double GetCredit(int id) {
        int tmp = NumTable[id][1];
        if (NumTable[id][0] == 1)
            return CA[tmp].GetCredit();
        return -1;
    }

    bool IsCredit(int id){
        return (NumTable[id][0] == 1);
    }
};
