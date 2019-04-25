#include <iostream>
#include <string>

#include "investor_class.h"

using namespace std;

Investor::Investor(void)
{
    net_worth=0;
    wallet_balance=0;
    total_transferred_money=0;
    temp_transferred_money=0;
    my_stocks[0]=0;
    my_stocks[1]=0;
    my_stocks[2]=0;
    my_stocks[3]=0;
    my_stocks[4]=0;
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

string Investor::get_name()
{
    return name;
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

double Investor::get_temp_transferred_money()
{
    return temp_transferred_money;
}

double Investor::get_my_stock(int n)
{
    return my_stocks[n];
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
