//
//  main.cpp
//  Bank account
//
//  Created by Israel Carvajal on 11/10/14.
//  Copyright (c) 2014 Israel Carvajal. All rights reserved.
//

#include <iostream>
#include "account.h"
#include "Savings.h"
#include "Checking.h"
#include "Loan.h"
#include <string>
using namespace std;




int main(int argc, const char * argv[])
{
   cout.setf(ios::fixed); // no scientific notation please
   cout.setf(ios::showpoint); // always show the decimal for real numbers
   cout.precision(2); // two digits after the decimal
   cout << "Please enter transactions below:\n";
   char input;
    string name;
    float amount;
    float rate;
    int num;
    
    Account * accounts[100];
    do
    {
        cout << "> ";
        cin >> input;
        
        
        
        switch (input)
        {
                
            case 's':
            {
                cin >> num >> name >> amount >> rate;
                cout << "new account...\n";
                Savings *sav = new Savings;
                //*accounts[num] = num;
                sav->setRate(rate);
                sav->setName(name);
                sav->setBalance(amount);
               // sav->setType(input);
                sav->display();
                accounts[num] = sav;
                break;
            }
            case 'c':
            {
                cin >> num >> name >> amount >> rate;
                cout << "new account...\n";
                Checking *check = new Checking;
                check->setCheckFee(rate);
                check->setName(name);
                check->setBalance(amount);
                check->display();
                accounts[num] = check;
                break;
            }
            case 'l':
            {
                cin >> num >> name >> amount >> rate;
                cout << "new account...\n";
                Loan *loan = new Loan;
                loan->setName(name);
                loan->setBalance(-amount);
                loan->setRate(rate);
                loan->display();
                accounts[num] = loan;
                break;
            }
            case 'u':
            {
                cin >> num;
                accounts[num]->update();
                accounts[num]->display();
                break;
            }
            case 't':
            {
                cin >> num >> amount;
                accounts[num]->setAmount(amount);
                accounts[num]->transaction();
                accounts[num]->display();
                break;
            }
            
                
            
            

              
                
        }
    }
    while (input != 'q');
    cout << "Goodbye\n";
    return 0;
}
