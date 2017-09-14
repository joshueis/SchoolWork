
//
//  Loan.h
//  Bank account
//
//  Created by Israel Carvajal on 11/10/14.
//  Copyright (c) 2014 Israel Carvajal. All rights reserved.
//

#ifndef Bank_account_Loan_h
#define Bank_account_Loan_h

class Loan : public Account
{
private:
    float rate;
public:
    inline float getRate() const { return rate;}
    void setRate(float rate) { this->rate = rate;}
    void display()
    {
        type = "loan";
        Account::display();
    }
    void update()
    {
       cout << "update...\n";
        cout << name << " (" << type << "):"
             << "  $" << (rate * balance) << " applied to account\n";
        this->balance *= (1 + rate);
    }
    void transaction ()
    {
       cout.setf(ios::fixed); // no scientific notation please
       cout.setf(ios::showpoint); // always show the decimal for real numbers
       cout.precision(2); // two digits after the decimal
       cout << "transaction...\n";
       this->balance += amount;
       cout << name << " (" << type << "): "
            << " $" << amount << " applied to account\n";
    }
};
#endif
