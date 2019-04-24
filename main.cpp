#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "investor_class.h"
#include "start.h"
#include "dashboard.h"
#include "money_management.h"
#include "stock_trading.h"
#include "stock_manipulation.h"

using namespace std;

int main()
{
    
    //vector <Investor> Investor_Vector;
    double stock_array[5];
    string stock_names[5]{"Google","Apple","Microsoft","Facebook","Amazon"};
    Investor user;
    int day=1;

    display();

    while(true)
    {
        share_manipulation();

        read_shares_into_array(stock_array);

        set_the_credit_limit(user);

        if(day%5==0)
        {
            user.reset_credit_balance();
        }
        
        switch(print_dashboard(user))
        {
            case 'a':
                
                adding_money(user);
                break;
            
            case 's':
            
                print_stocks(stock_array, stock_names);
                trade_stocks(user, stock_array, stock_names, day);
                break;
                
            case 'n':
                
                break;

            case 'e':
                
                cout<<"Thank you for using iStock"<<endl<<endl;
                cout<<"See you soon !";
                exit(0);
                break;
            
            default:
                
                break;
        }
        
        ++day;
    }

    return 0;
}
