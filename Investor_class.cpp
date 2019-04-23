#include "Investor_Class.h"
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

void Investor::print_stocks()
{
    cout<<"Apple     : "<<my_stock_1<<endl;
    cout<<"Google    : "<<my_stock_2<<endl;
    cout<<"Amazon    : "<<my_stock_3<<endl;
    cout<<"Facebook  : "<<my_stock_4<<endl;
    cout<<"Microsoft : "<<my_stock_5<<endl;
}

bool Investor::add_money_to_wallet(double input)
{
    if(get_credit_balance == 0)
    {
        cout<<"Max Credit reached"<<endl;
        cout<<"Cannot add any more money"<<endl<<endl;
    }
        
    label1:

    if(in_transfer_money + input > credit_limit)
    {
        cout<<"Cannot transfer above credit limit, please try again"<<endl<<endl;
        cout<<"Press 0 to exit money adding function";
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
