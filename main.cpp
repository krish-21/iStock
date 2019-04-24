#include <iostream>
#include <string>
#include <vector>
#include "investor_class.h"
#include "start.h"
#include "dashboard.h"
#include "stock_trading.h"
//#include "Stock_Manipulation.h"

using namespace std;

void set_the_credit_limit(Investor user)
{
    double limit;

    cout<<"Please set your credit limit";
    cin>>limit;
        
    user.set_credit_limit(limit);
}

void adding_money(Investor user)
{
    char ans='y';
    double money_to_add;

    while(ans=='y')
    {
        cout<<"How much money do you want to add to your wallet"<<endl;
        cout<<"Please keep your credt limit in mind!"<<endl<<endl;

        cin>>money_to_add;

        if(money_to_add<=0)
        {
            cout<<"Invalid input !"<<endl<<"Do you want to try again (y/n?"<<endl;
            cin>>ans;
        }

        else
        {
            user.add_money_to_wallet(money_to_add);
            break;
        }
        
    }
}


void buy_and_sell(Investor user/*, _________________*/)
{
    if(Buy_Stock(user/*, _____________*/))
        cout<<"";

    if(Sell_Stock(user/*, ____________*/))
        cout<<"";    
}

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
            
            case 's': // to trade stock
            
                buy_and_sell(user/*, ______________*/);
                break;    
            
                
            case 'n':
                
                break;

            case '\n':
                
                cout<<"Thank you for using iStock"<<endl<<endl;
                cout<<"See you soon !";
                exit(0);
                break;
        }
        
        ++day;
    }

    return 0;
}
