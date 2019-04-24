#ifndef Investor_h
#define Investor_h

#include <string>

using namespace std;

class Investor
{
    public:
    
    void set_name(string);
    void set_net_worth(double);
    void set_wallet_balance(double);
    void set_credit_limit(double);
 
    double get_net_worth();
    double get_wallet_balance();
    double get_credit_balance();
    double get_my_stock(int);
    void print_stocks();
    
    bool add_money_to_wallet(double);
    void buy_my_stock(int, double);


    private:

    string name;

    double net_worth;
    double wallet_balance;
    double credit_limit;
    double in_transfer_money;

    double my_stock_1;
    double my_stock_2;
    double my_stock_3;
    double my_stock_4;
    double my_stock_5;

};
