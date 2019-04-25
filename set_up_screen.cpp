#include <iostream>
#include <string>

#include "investor_class.h"
#include "set_up_screen.h"

using namespace std;

void set_up_function(Investor &user)
{
    string name;
    
    cout<<"Welcome to iStock"<<endl<<endl;

    cout<<"Please enter your name : ";

    cin>>name;

    user.set_name(name);
    
    cout<<endl<<endl<<"You will now have to set the credit limit for yourself"<<endl<<endl;

    cout<<"Please note that this credit limit will be fixed during the entire duration of your virtual stock trading experience.";

}