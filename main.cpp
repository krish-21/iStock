#include <iostream>
#include <string>
#include <vector>
#include "investor_class.h"
#include "start.h"
#include "dashboard.h"
#include "stock_trading.h"
//#include "Stock_Manipulation.h"

using namespace std;

void buy_and_sell(Investor user, vector <double> Stock_Vector)
{
    if(Buy_Stock(user, Stock_Vector))
        cout<<"";
    if(Sell_Stock(user, Stock_Vector))
        cout<<"";
    
}

int main()
{
    
    //vector <Investor> Investor_Vector;
    vector <double> Stock_Vector;
    Investor user;

    display();

    while(true)
    {
        //stock_manipulation_function(Stock_Vector)

        switch(print_dashboard(user))
        {
            case 's':
            
                buy_and_sell(user, Stock_Vector);
                break;    
            
                
            case 'n':
                
                break;

            case '\n':
                
                cout<<"Thank you for using iStock"<<endl<<endl;
                cout<<"See you soon !";
                exit(0);
                break;
        }
        
    }

    return 0;
}
