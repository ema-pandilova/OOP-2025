//
// Created by ema on 19.4.25.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class DebitAccount {
protected:
    char name[100];
    char number[17];
    double balance;
public:
    DebitAccount(char *name="", char *number="1000000000000000", double balance=0.0) {
        strcpy(this->name, name);
        strcpy(this->number, number);
        this->balance = balance;
    }
    DebitAccount(const DebitAccount &d) {
        strcpy(this->name, d.name);
        strcpy(this->number, d.number);
        this->balance = d.balance;
    }
    void report() {
        cout<<"Name: "<<name<<" Credit card number: "<<number<<" Balance: "<<balance<<endl;
    }
    void deposit(double amount) {
        this->balance += amount;
    }
    void withdraw(double amount) {
        if(amount<=balance) {
            balance -= amount;
        }
        else {
            cout<<"Transaction not  allowed"<<endl;
        }
    }
};

class CreditAccount : public DebitAccount {
    double minus;
    double limit;
    double debt;
    double interest; //0.02 2% 0.2 20%
public:
    CreditAccount(char *name="", char *number="1000000000000000", double balance=0.0, double limit=1000, double interest=0.01) : DebitAccount(name, number, balance) {
        this->limit = limit;
        this->interest = interest;
        this->debt = 0;
        this->minus = 0;
    }
    void report() {
        DebitAccount::report();
        cout<<"Minus: "<<minus<<" Limit: "<<limit<<" Debt: "<<debt<<" Interest: "<<interest<<endl;
    }
    void deposit(double amount) { // amount=10, debt=1000,
       if(debt>0) {
           double diff = amount - debt;
           if(diff<0) {
               debt -= amount;
               minus -= amount;
           }
           else {
               debt =0;
               minus=0;
               balance+=diff;
           }

       }
        else {
            balance += amount;
        }
    }
    void withdraw(double amount) { //amount=1000, balance = 10, limit=2000, minus=1000, interest=0.1
        if(amount <= balance+limit-minus) {
            double diff = amount - balance;
            balance -= amount;
            if(balance<0) {
                balance=0;
            }
            if(diff>0) {
                minus+=diff;
                debt+=diff + (diff*interest); //990 + 0.01*990
            }

        }
        else {
            cout<<"Transaction not  allowed"<<endl;
        }
    }
};

int main() {
    DebitAccount da("ema","1000000000000000", 1000);
    da.report();
    da.withdraw(10);
    da.report();
    CreditAccount ca("ema","1000000000000000", 1000);
    ca.report();
    ca.withdraw(1100);
    ca.report();
    ca.withdraw(900);
    ca.report();
    ca.withdraw(10);
    ca.report();
    return 0;

}