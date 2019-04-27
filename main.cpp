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
    
    //initialize basic variables

    //stores the stock values
    double stock_array[5];

    //stores the stock values
    string stock_names[5]{"Alphabet","Apple","Microsoft","Facebook","Amazon"};
    
    //object of class investor & used throught the program
    Investor user;
    
    //keeps track of the loop to update the stock values
    int day=1;
    char action, ans = 'y', pause;

    //prints DISCLAIMER
    //prints the initial scrren & gets the user's name
    set_up_function(user);
    
    //prints the details about credit limit & gets the credit limit
    set_the_credit_limit(user);

    while(true)
    {
        //changes the stock values at the start of each day
        share_manipulation();

        //changes the stock values to the current stock values 
        read_shares_into_array(stock_array);

        if(day%5==0)
        {
            //resets the credit balance every 5 days
            user.reset_credit_balance();
        }

        //calculates the net worth for the dashboard function
        calculate_net_worth(user, stock_array);

        label1:
        
        //gets the action from the user through the dashboard function
        action = print_dashboard(user, day);
        
        switch(action)
        {
            case 'a':

                //adds money to the wallet function
                cout<<endl<<endl;
                adding_money(user);
                break;
            
            case 't':
            
                //goes to the stock trading mode
                cout<<endl<<endl;
                trade_stocks(user, stock_array, stock_names, day);
                break;
                
            case 's':

                //goes to the record searching function
                search_records();
                break;
            
            case 'v':
                
                //goes to the sorting function
                sorting();
                break;
            
            case 'h':

                //goes to the stock history function
                cout<<"case h"<<endl;
                print_history(stock_names);
                break;
            
            case 'n':
                
                //proceeds to the next day in the program
                cout<<"Proceeding to the next day"<<endl<<endl;
                break;

            case 'e':

                //exits iStock
                cout<<endl<<endl<<endl;
                cout<<"Thank you for using iStock"<<endl<<endl;
                cout<<"See you again !!!"<<endl<<endl<<endl;
                exit(0);
                break;
            
            default:
                
                //case for invalid inout
                cout<<"Invalid input !"<<endl<<endl;
                break;
        }

        //if user does not choose to proceed to next day,
        //ask after one function is completed to proceed to next day or not        
        if(action != 'n')
        {
            cout<<"Proceed to the next day (y/n) ?  ";
            cin>>ans;
            cout<<endl<<endl;

            if(ans !='y')
                goto label1;
        }
        
        cout<<"####################################################################################"<<endl;
        cout<<"#############################Proceeding to the next day#############################"<<endl;
        cout<<"####################################################################################"<<endl;

        //increment the day at the end of the switch case
        ++day;
        
        //for spacing
        cout<<endl<<endl<<endl<<endl;
    }

    return 0;
}
