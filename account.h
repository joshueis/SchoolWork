//
//  account.h
//  Bank account
//
//  Created by Israel Carvajal on 11/10/14.
//  Copyright (c) 2014 Israel Carvajal. All rights reserved.
//

#ifndef Bank_account_account_h
#define Bank_account_account_h

#include<iostream>
#include<string>
using namespace std;
class Account
{
protected:
    string name;
    float balance;
    float amount;
    string type;
public:
    void setName(string name)
    {
        this->name = name;
    }
    void setBalance(float balance)
    {
        this->balance = balance;
    }
    inline float getAmount() const { return amount;}
    void setAmount(float amount) { this->amount = amount; }
    virtual void display()
    {
        cout.setf(ios::fixed); // no scientific notation please
        cout.setf(ios::showpoint); // always show the decimal for real numbers
        cout.precision(2); // two digits after the decimal
        
        cout << name << " (" << type << "):"
             << "  balance is $" << balance << endl << endl;
    }
    virtual void update() {}
    virtual void transaction() {}
    
    
};

#endif
