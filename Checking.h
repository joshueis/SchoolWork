//
//  Checking.h
//  Bank account
//
//  Created by Israel Carvajal on 11/10/14.
//  Copyright (c) 2014 Israel Carvajal. All rights reserved.
//

#ifndef Bank_account_Checking_h
#define Bank_account_Checking_h
#define BCFEE -25
class Checking : public Account
{
private:
    
    float checkFee;
    int checks;
    bool bouncedCheckFee;
public:
    void setCheckFee(float checkFee) { this->checkFee = checkFee;}
    inline int getCheckFee() const { return checkFee;}
    void display()
    {
        type = "checking";
        Account::display();
    }
    void update()
    {
        cout << "update...\n";
        this->balance -= (checks * checkFee);
        
        cout << name << " (" << type << "): "
            << " $-" << (checks * checkFee) << " applied to account\n";
        checks = 0;
        
        
    }
    void transaction()
    {
        cout << "transaction...\n";
        
        if (this->amount < 0)
        {
            checks++; //writing a check
            if (-(this->amount) > this->balance)
            {
                cout << name << " (" << type << "):"
                     << "  $" << amount << " rejected (insufficient funds)\n";
                cout << name << " (" << type << "):" << "  $"
                     << (float)BCFEE << " applied to account\n";
                bouncedCheckFee = true;
                if (bouncedCheckFee)
                {
                    this->balance += BCFEE;
                }
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
    }
};
#endif
