
//
//  FullTime.h
//  Bank account
//
//  Created by Israel Carvajal on 11/10/14.
//  Copyright (c) 2014 Israel Carvajal. All rights reserved.
//

#ifndef Bank_account_Savings_h
#define Bank_account_Savings_h

class Savings : public Account
{
private:
    float rate;
    
public:
    float getRate() const { return rate;}
    void setRate(float rate) { this->rate = rate;}
    void display()
    {
        type = "savings";
        Account::display();
        
    }
    void update()
    {  
       cout << "update...\n";
       cout << name << " (" << type << "): "
            << " $" << (rate * balance) << " applied to account\n";
       this->balance *= (1.0 + rate);

    }
    void transaction()
    {
       cout << "transaction...\n";

       if (this->amount < 0)
        {
            if (-(this->amount) > this->balance)
            {
                cout << name << " (" << type << "): "
                     << " $" << amount << " rejected (insufficient funds)\n";
            }
            else
            {
                this->balance += amount;
                cout << name << " (" << type << "): "
                     << " $" << amount << " applied to account\n";
            }
            

        }
        else
        {
            this->balance += amount;
            cout << name << " (" << type << "): "
                 << " $" << amount << " applied to account\n";
        }
        
        //this->balance += amount;
    }
};
#endif
