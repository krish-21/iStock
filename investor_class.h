#ifndef Investor_h
#define Investor_h

#include <string>

using namespace std;

class Investor
{
    public:

    Investor();
    
    void set_name(string);
    void set_net_worth(double);
    void set_wallet_balance(double);
    void set_credit_limit(double);
    void reset_credit_balance();
 
    string get_name();
    double get_net_worth();
    double get_wallet_balance();
    double get_credit_limit();
    double get_credit_balance();
    double get_temp_transferred_money();
    double get_my_stock(int);
    void print_my_stocks();
    
    void add_money_to_wallet(double);
    void buy_my_stock(int, double, double);
    void sell_my_stock(int, double, double);


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