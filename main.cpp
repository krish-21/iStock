#include <iostream>
#include <string>
#include <vector>
#include "Investor_Class.h"
#include "start.h"
#include "dashboard.h"
#include "Stock_Trading.h"
//#include "Stock_Manipulation.h"

using namespace std;

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
            
                if(Buy_Stock(user, Stock_Vector))
                    cout<<"";
                if(Sell_Stock(user, Stock_Vector))
                    cout<<"";
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
