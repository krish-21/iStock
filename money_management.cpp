#include <iostream>

#include "investor_class.h"
#include "money_management.h"

void set_the_credit_limit(Investor &user)
{
    double limit;
    label1:

    cout<<"                               (Recommended > $ 1000)"<<endl;
    cout<<"Please set your credit limit : $ ";
    cin>>limit;

    //credit limit cannot be zero or negative
    if(limit <= 0)
    {
        cout<<endl<<endl;
        cout<<"Please enter a positive number ";
        cout<<endl<<endl;
    }
    
    cout<<endl<<endl;
        
    //calls the member function of class Investor to set the credit limit
    user.set_credit_limit(limit);
}

void adding_money(Investor &user)
{
    char ans='y';
    double money_to_add;

    //if credit balance is zero, go back to the dashboard
    if(user.get_credit_balance() == 0)
        {
            cout<<"Max Credit reached"<<endl<<endl;
            cout<<"Cannot add any more money"<<endl<<endl<<endl<<endl;
            return;
        }

    while(ans=='y')
    {
        cout<<"How much money do you want to add to your wallet ?"<<endl<<endl;
        cout<<"Please keep your credt limit in mind!        Credit Limit   =  $ "<<user.get_credit_limit()<<endl;
        cout<<"                                             Credit Balance =  $ "<<user.get_credit_balance()<<endl;
        cout<<"Amount to add :  $ ";

        cin>>money_to_add;

        //cannot add negative sums of money
        if(money_to_add < 0)
        {
            cout<<"Cannot add negative sums of money  !"<<endl<<"Do you want to try again (y/n)?"<<endl;
            cin>>ans;
        }

        //cannot add zero money
        else if(money_to_add == 0)
        {
            cout<<endl;
            cout<<"Cannot add zero  !"<<endl<<"Do you want to try again (y/n)?  ";
            cin>>ans;
        }

        else
        {
            //money added should not exceed credit balacnce
            if(money_to_add > user.get_credit_balance())
            {
                cout<<endl;
                cout<<"Cannot add exceed credit balance !"<<endl<<"Do you want to try again (y/n)?  ";
                cin>>ans;
            }

            //when all checks are made
            else
            {
                //invoke member funcion of class Investor to add money to the wallet
                user.add_money_to_wallet(money_to_add);
                break;
            }   
        }
    }

    //success message
    cout<<endl<<endl<<"$ "<<money_to_add<<" successfully added to Wallet !"<<endl<<endl;
}

void calculate_net_worth(Investor &user, double stock_srray[5])
{
    double net_worth=0;

    //loop for each stock
    for(int i=0; i<5; ++i)
    {
        //add the values of each stock multiplied by the number of stocks owned
        net_worth += ( (stock_srray[i]) * (user.get_my_stock(i)) );
    }   

    //invoke the member fucntion of the class Investor to se the new net worth
    user.set_net_worth(net_worth);
}
