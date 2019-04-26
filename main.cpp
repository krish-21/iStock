#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "investor_class.h"
#include "set_up_screen.h"
#include "dashboard.h"
#include "money_management.h"
#include "stock_manipulation.h"
#include "stock_trading.h"
#include "search_data.h"
#include "sort.h"
#include "stock_history.h"

using namespace std;

int main()
{
    
    double stock_array[5];
    string stock_names[5]{"Alphabet","Apple","Microsoft","Facebook","Amazon"};
    Investor user;
    int day=1;
    char action, ans = 'y', pause;

    set_up_function(user);
    
    set_the_credit_limit(user);

    while(true)
    {
        share_manipulation();

        read_shares_into_array(stock_array);

        if(day%5==0)
        {
            user.reset_credit_balance();
        }

        calculate_net_worth(user, stock_array);

        label1:
        
        action = print_dashboard(user, day);
        
        switch(action)
        {
            case 'a':

                cout<<endl<<endl;
                adding_money(user);
                break;
            
            case 't':
            
                cout<<endl<<endl;
                trade_stocks(user, stock_array, stock_names, day);
                break;
                
            case 's':

                search_records();
                break;
            
            case 'v':
                
                sorting();
                break;
            
            case 'h':

                cout<<"case h"<<endl;
                print_history(stock_names);
                break;
            
            case 'n':
                cout<<"Proceeding to the next day"<<endl<<endl;
                break;

            case 'e':

                cout<<"Thank you for using iStock"<<endl<<endl;
                cout<<"See you again !!!";
                exit(0);
                break;
            
            default:
                cout<<"Invalid input !"<<endl<<endl;
                break;
        }

        if(action != 'n')
        {
            cout<<"Proceed to the next day (y/n) ?  ";
            cin>>ans;
            cout<<endl<<endl;

            if(ans !='y')
                goto label1;
        }
        
        cout<<"#############################"<<"Proceeding to the next day"<<"#############################"<<endl<<endl<<endl;
        ++day;

        cout<<"Enter \"c\" to continue  ";
        cin>>pause;
        cout<<endl<<endl<<endl<<endl;
    }

    return 0;
}
