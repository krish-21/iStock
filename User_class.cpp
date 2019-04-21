#include "User_Class.h"
#include <iostream>
#include <string>

using namespace std;

User::set_Name(input)
{
    Name = input;
}

User::set_NetWorth()
{
    NetWorth = 0;
}

User::set_Wallet_Balance()
{
    Wallet_Balance = 0;
}

User::set_credit_limit(input)
{
    credit_limit = input;
}

User::get_NetWorth()
{
    return NetWorth;
}

User::get_Wallet_Balance()
{
    return Wallet_Balance;
}

User::is_credit_available()
{
    if(in_transfer_money < credit_limit)
        return true;
    
    else
    return false
    
}

User::add_money_to_wallet(input)
{
    if(!is_credit_available())
        return false;
    
    if(in_transfer_money + input > credit_limit)
        return false;
    
    in_transfer_money += input;

    Wallet_Balance += input;
    
}

User::buy_Stock()
{
    if(get_Wallet_Balance = 0)
        return false;
}

User::sell_Stock()
{

}