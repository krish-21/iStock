#include "investor_class.h"
#include <iostream>
#include <string>

using namespace std;

Investor::Investor()
{
    net_worth=0;
    wallet_balance=0;
}

void Investor::set_name(string input)
{
    name = input;
}

void Investor::set_net_worth(double input)
{
    net_worth = input;
}

void Investor::set_wallet_balance(double input)
{
    wallet_balance = input;
}

void Investor::set_credit_limit(double input)
{
    credit_limit = input;
}

double Investor::get_net_worth()
{
    return net_worth;
}

double Investor::get_wallet_balance()
{
    return wallet_balance;
}

double Investor::get_credit_balance()
{
    return (credit_limit - in_transfer_money);
}

double Investor::get_my_stock(int n)
{
    return my_stock[n-1];
}

void Investor::print_stocks()
{
    cout<<"Apple     : "<<my_stock[0]<<endl;
    cout<<"Google    : "<<my_stock[1]<<endl;
    cout<<"Amazon    : "<<my_stock[2]<<endl;
    cout<<"Facebook  : "<<my_stock[3]<<endl;
    cout<<"Microsoft : "<<my_stock[4]<<endl;
}

bool Investor::add_money_to_wallet(double input)
{
    if(get_credit_balance() == 0)
    {
        cout<<"Max Credit reached"<<endl;
        cout<<"Cannot add any more money"<<endl<<endl;
    }
        
    label1:

    if(in_transfer_money + input > credit_limit)
    {
        cout<<"Cannot transfer above credit limit, please try again"<<endl<<endl;
        cout<<"Press 0 to exit money adding function"<<endl<<endl;
        cin>>input;
        
        if(input == 0)
        {
            return false;
        }
        
        else
        {
            goto label1;
        }
        
    }
    
    in_transfer_money += input;

    wallet_balance += input;

    
}

bool Investor::buy_my_stock(int n, double input)
{
          
    if(my_stock[n-1] + input <=100)
    {
        my_stock[n-1] += input;
            return true;
    }
            
    else
    {
        cout<<"Cannot own more than 100 percentof company"<<endl<<endl;
        return false;
    }

}
