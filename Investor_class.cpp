
#include "Investor_Class.h"
#include <iostream>
#include <string>

using namespace std;

Investor::set_Name(string input)
{
    Name = input;
}

Investor::set_NetWorth()
{
    NetWorth = 0;
}

Investor::set_Wallet_Balance()
{
    Wallet_Balance = 0;
}

Investor::set_credit_limit(double input)
{
    credit_limit = input;
}

Investor::get_NetWorth()
{
    return NetWorth;
}

Investor::get_Wallet_Balance()
{
    return Wallet_Balance;
}

Investor::print_stocks()
{
    cout<<"Apple     : "<<my_Apple<<endl;
    cout<<"Google    : "<<my_Google<<endl;
    cout<<"Amazon    : "<<my_Amazon<<endl;
    cout<<"Facebook  : "<<my_Facebook<<endl;
    cout<<"Microsoft : "<<my_Microsoft<<endl;
}

Investor::is_credit_available()
{
    if(in_transfer_money < credit_limit)
        return true;
    
    else
    return false
    
}

Investor::add_money_to_wallet(double input)
{
    if(!is_credit_available())
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
        input == 0 ? return : goto label1;
    }
        
    
    in_transfer_money += input;

    Wallet_Balance += input;

    
}

Investor::buy_Stock()
{
    if(get_Wallet_Balance = 0)
        return false;
}

Investor::sell_Stock()
{

}