#include <iostream>
#include <string>

#include "investor_class.h"
#include "dashboard.h"

using namespace std;

char print_dashboard(Investor &user)
{
    char a;
    
    cout<<"***********************************************************************";
    cout<<"***********************************************************************";
    cout<<endl<<endl;

    cout<<user.get_name()<<"'s Portfolio :"<<endl<<endl<<endl;

    cout<<"Net Worth : "<<user.get_net_worth()<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    user.print_my_stocks();
    cout<<endl<<endl; 

    cout<<"Money in Wallet : "<<user.get_wallet_balance()<<endl<<endl;
    
    cout<<"Current Credit Balance : "<<user.get_credit_balance()<<endl<<endl<<endl;

    cout<<"Press \"a\" to add money to wallet"<<endl<<endl;
    cout<<"Press \"s\" to begin Stock Trading"<<endl<<endl;
    cout<<"Press \"t\" to look up Transaction Records"<<endl<<endl;
    cout<<"Press \"n\" to proceed to next day"<<endl<<endl;
    cout<<"Press \"e\" to exit the program"<<endl<<endl;

    cin>>a;

    return a;
}
