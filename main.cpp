#include <iostream>
#include <string>
#include <vector>
#include "investor_class.h"
#include "start.h"
#include "dashboard.h"
#include "money_management.h"
#include "stock_trading.h"
//#include "stock_manipulation.h"

using namespace std;

int main()
{
    
    //vector <Investor> Investor_Vector;
    vector <double> Stock_Vector;
    Investor user;
    int day=1;

    display();

    while(true)
    {
        //stock_manipulation_function(Stock_Vector)

        if(day%5==0)
        {
            user.reset_credit_balance();
        }
        
        switch(print_dashboard(user))
        {
            case 'a':
                
                adding_money(user);
                break;
            
            case 's': // to trade stock
            
                trade_stocks(user, Stock_Vector);
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
