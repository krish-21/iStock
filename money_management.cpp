#include <iostream>

#include "investor_class.h"
#include "money_management.h"

void set_the_credit_limit(Investor &user)
{
    double limit;

    cout<<"                               (Recommended to be at least 1000)"<<endl;
    cout<<"Please set your credit limit : ";
    cin>>limit;
    cout<<endl<<endl;
        
    user.set_credit_limit(limit);
}

void adding_money(Investor &user)
{
    char ans='y';
    double money_to_add;

    if(user.get_credit_balance() == 0)
        {
            cout<<"Max Credit reached"<<endl;
            cout<<"Cannot add any more money"<<endl<<endl;
            return;
        }

    while(ans=='y')
    {
        cout<<"How much money do you want to add to your wallet ?"<<endl<<endl;
        cout<<"Please keep your credt limit in mind!        Credit Limit   =  "<<user.get_credit_limit()<<endl;
        cout<<"                                             Credit Balance =  "<<user.get_credit_balance()<<endl;
        cout<<"Amount to add :  ";

        cin>>money_to_add;

        if(money_to_add < 0)
        {
            cout<<"Cannot add negative sums of money  !"<<endl<<"Do you want to try again (y/n)?"<<endl;
            cin>>ans;
        }

        else if(money_to_add == 0)
        {
            cout<<endl;
            cout<<"Cannot add zero  !"<<endl<<"Do you want to try again (y/n)?  ";
            cin>>ans;
        }

        else
        {
            if(money_to_add > user.get_credit_balance())
            {
                cout<<endl;
                cout<<"Cannot add exceed credit balance !"<<endl<<"Do you want to try again (y/n)?  ";
                cin>>ans;
            }

            else
            {
                user.add_money_to_wallet(money_to_add);
                break;
            }   
        }
    }

    cout<<endl<<endl<<money_to_add<<"USD successfully added to Wallet !"<<endl<<endl;
}

void calculate_net_worth(Investor &user, double stock_srray[5])
{
    double net_worth=0;

    for(int i=0; i<5; ++i)
    {
        net_worth += ( (stock_srray[i]) * (user.get_my_stock(i)) );
    }   

    user.set_net_worth(net_worth);
}