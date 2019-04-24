#include <iostream>
#include "investor_class.h"
#include "money_management.h"

void set_the_credit_limit(Investor &user)
{
    double limit;

    cout<<"Please set your credit limit";
    cin>>limit;
        
    user.set_credit_limit(limit);
}

void adding_money(Investor &user)
{
    char ans='y';
    double money_to_add;

    while(ans=='y')
    {
        cout<<"How much money do you want to add to your wallet"<<endl;
        cout<<"Please keep your credt limit in mind!"<<endl<<endl;

        cin>>money_to_add;

        if(money_to_add<=0)
        {
            cout<<"Invalid input !"<<endl<<"Do you want to try again (y/n?"<<endl;
            cin>>ans;
        }

        else
        {
            user.add_money_to_wallet(money_to_add);
            break;
        }
        
    }
}