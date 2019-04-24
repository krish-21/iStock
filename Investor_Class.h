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
    void reset_credit_balance();
 
    double get_net_worth();
    double get_wallet_balance();
    double get_credit_balance();
    //double get_my_stock(int);
    void print_my_stocks();
    
    bool add_money_to_wallet(double);
    bool buy_my_stock(int, double);


    private:

    string name;

    double net_worth;
    double wallet_balance;
    double credit_limit;
    double total_transferred_money;
    double temp_transferred_money;

    double my_stocks[5];

};

#endif