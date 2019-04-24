#include "investor_class.h"
#include <iostream>
#include <string>

using namespace std;

Investor::Investor()
{
    net_worth=0;
    wallet_balance=0;
    total_transferred_money=0;
    temp_transferred_money=0;
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

void Investor::reset_credit_balance()
{
    temp_transferred_money=0;
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
    return (credit_limit - temp_transferred_money);
}

double Investor::get_my_stock(int n)
{
    return my_stocks[n-1];
}

void Investor::print_my_stocks()
{
    cout<<"Alphabet  : "<<my_stocks[0]<<endl;
    cout<<"Apple     : "<<my_stocks[1]<<endl;
    cout<<"Microsoft : "<<my_stocks[2]<<endl;
    cout<<"Facebook  : "<<my_stocks[3]<<endl;
    cout<<"Amazon    : "<<my_stocks[4]<<endl;
}

void Investor::add_money_to_wallet(double input)
{
    if(get_credit_balance() == 0)
    {
        cout<<"Max Credit reached"<<endl;
        cout<<"Cannot add any more money"<<endl<<endl;
    }
        
    label1:

    if(temp_transferred_money + input > credit_limit)
    {
        cout<<"Cannot transfer above credit limit, please try again"<<endl<<endl;
        cout<<"Press 0 to exit money adding function"<<endl<<endl;
        cin>>input;
        
        if(input == 0)
        {
            return;
        }
        
        else
        {
            goto label1;
        }
        
    }
    
    temp_transferred_money += input;

    total_transferred_money += input;

    wallet_balance += input;

    
}

void Investor::buy_my_stock(int n, double no_of_stocks, double amount_spent)
{
    my_stocks[n-1] += no_of_stocks;
    wallet_balance -= amount_spent;
}

void Investor::sell_my_stock(int n, double no_of_stocks, double sale_amount)
{
    my_stocks[n-1] -= no_of_stocks;
    wallet_balance += sale_amount;
}
