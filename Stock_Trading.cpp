#include "investor_class.h"
#include <vector>
#include <iostream>

bool Buy_Stock(Investor user, vector <double> Stock_Vector)
{
    if(user.get_wallet_balance() == 0)
    {
        cout << "Insuficient Wallet Balance !" << endl << "Please add money to your wallet";
        return false;
    }

    return true;
        
}

bool Sell_Stock(Investor user, vector <double> Stock_Vector)
{
    if(user.get_net_worth() == 0)
    {
        cout << "You do not own anything to sell !!!" << endl;
        cout << "Please buy some stocks to start selling" << endl << endl;
        return false;
    }

    return true;

}
