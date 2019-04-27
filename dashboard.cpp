#include <iostream>
#include <iomanip>
#include <string>

#include "investor_class.h"
#include "dashboard.h"

using namespace std;

char print_dashboard(Investor &user, int day)
{
    char a;
    
    //to show a particular number of decimal points only & not show scientific notation for large numbers
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"******************************************---DASHBOARD---******************************************";
    cout<<endl<<endl;

    //invoke the member function of class Investor the get the name
    cout<<user.get_name()<<"'s Portfolio :                                         Day "<<day<<endl<<endl<<endl;

    //invoke the member function of class Investor the get the net worth
    cout<<"Net Worth : "<<"$ "<<user.get_net_worth()<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    //invoke the member function of class Investor the print the stocks owned
    user.print_my_stocks();
    cout<<endl<<endl;

    //invoke the member function of class Investor the get wallet balance
    cout<<"Wallet Balance   : "<<"$ "<<user.get_wallet_balance()<<endl<<endl;
    
    //invoke the member function of class Investor the get the credi balance
    cout<<"Credit Balance   : "<<"$ "<<user.get_credit_balance()<<endl<<endl<<endl;

    //print the iStock Menu
    cout<<"MENU :"<<endl<<endl;
    cout<<"        \"a\" to add money to wallet"<<endl<<endl;
    cout<<"        \"t\" to begin Stock Trading"<<endl<<endl;
    cout<<"        \"s\" to search for specific transanctions"<<endl<<endl;
    cout<<"        \"v\" to sort and view all transactions"<<endl<<endl;
    cout<<"        \"h\" to view the hisory of prices"<<endl<<endl;
    cout<<"        \"n\" to proceed to next day"<<endl<<endl;
    cout<<"        \"e\" to exit the program"<<endl<<endl;

    cout<<"Action -  ";
    
    //get the intended action character from the user
    cin>>a;

    return a;
}
