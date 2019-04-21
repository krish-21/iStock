#ifndef User_h
#define User_h

#include<string>

using namespace std;

Class User
{
    public:
    
    void set_Name(string);
    void set_NetWorth();
    void set_Wallet_Balance();
    void set_credit_limit();

    double get_NetWorth();
    double get_Wallet_Balance();
    
    bool add_money_to_wallet(double);
    bool is_credit_available();
    bool buy_Stock();
    void sell_Stock();
    

    private:

    string Name;

    double NetWorth;
    double Wallet_Balance;
    double credit_limit;
    double in_transfer_money;

    double my_Apple;
    double my_Google;
    double my_Amazon;
    double my_Facebook;
    double my_Microsoft;

};