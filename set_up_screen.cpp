#include <iostream>
#include <string>

#include "investor_class.h"
#include "set_up_screen.h"

using namespace std;

void set_up_function(Investor &user)
{
    string name;
    
    //print the fullscreen disclaimer
    cout<<endl<<endl<<endl;
    cout<<"DISCLAIMER : "<<"For the best experience of iStock :"<<endl<<endl;
    cout<<"Please set the terminal to Full Screen Mode...   Thank you !"<<endl<<endl;;

    //print the iStock Header
    cout<<endl<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl<<endl;
    cout<<"-----------------------------------------------------------------------"<<"iStock"<<"-----------------------------------------------------------------------"<<endl<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl;
    cout<<"*****************************************************************************************************************************************************"<<endl<<endl<<endl;

    cout<<"Please enter your name : ";

    cin>>name;

    //invoke the member function of class Investor the set the name
    user.set_name(name);
    
    //Print a small explanationon credit limit
    cout<<endl<<endl<<"IMPORTANT - To stop, over-spending, you will have to set a credit limit for yourself."<<endl<<endl;

    cout<<"            The credit limit will be fixed during the entire duration of your virtual stock trading experience."<<endl<<endl<<endl;
    cout<<"NOTE - The credit limit will refresh every 5 days of stock trading"<<endl<<endl<<endl;

}
