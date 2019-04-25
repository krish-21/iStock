#include <vector>
#include <iostream>
#include <fstream>
#include "investor_class.h"
#include "stock_trading.h"

using namespace std;

void buy_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    
    if(user.get_wallet_balance() == 0)
    {
        cout<<"Insuficient Wallet Balance !"<<endl<<"Please add money to your wallet"<<endl<<endl;
        return;
    }

    int n;
    double purchase_amount, no_of_stocks;
    char ans = 'y';

    string temp_filename = "records"; //uid from main whch will come from display()
    string filename = temp_filename + ".txt";
    ofstream fout;
    fout.open(filename, ios::app);

    label1:

    cout<<endl<<endl;

    cout<<"Which stock do you want to buy ?"<<endl<<endl;
    cout<<"Enter the S.No of the corresponding Stock (1-5) :  ";
    cin>>n;

    if(n<1 || n>5)
    {
        cout<<"Invalid input";
        cout<<"Do you want to try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
        else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    
    }

    cout<<endl;

    cout<<"How many stocks of "<<stock_names[n-1]<<" do you want to buy ?"<<endl<<endl;
    cin>>no_of_stocks;

    if(no_of_stocks < 0)
    {
        cout<<"Cannot buy negative number of stocks !"<<endl;
        cout<<"Do you want tot try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }
    
    else if(no_of_stocks == 0)
    {
        cout<<"Cannot buy zero stocks !"<<endl;
        cout<<"Do you want tot try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }
    
    purchase_amount = no_of_stocks * stock_array[n-1];

    if(purchase_amount > user.get_wallet_balance())
    {
        cout<<"Insufficient Wallet Balance !"<<endl;
        cout<<"Do you want tot try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }

    cout<<"No of stocks bought = "<<no_of_stocks<<endl<<endl;
    cout<<"Amount Spent = "<<purchase_amount<<endl<<endl;

    user.buy_my_stock(n, no_of_stocks, purchase_amount);
        
    cout<<"Stock purchase successful"<<endl<<endl;
    fout<<"B"<<" "<<purchase_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();
        
}

void sell_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    if(user.get_net_worth() == 0)
    {
        cout << "You do not own anything valuable to sell !!!" << endl;
        cout << "Please increase your networth to start selling" << endl << endl;
        return;
    }

    char ans;
    int n;
    double sale_amount, no_of_stocks;

    string temp_filename = "records"; //uid from main whch will come from display()
    string filename = temp_filename + ".txt";
    ofstream fout;
    fout.open(filename, ios::app);

    label1:
    
    cout<<"Which stock do you want to sell ? :   ";
    cin>>n;
    cout<<endl;
    cout<<"How many stocks of "<<stock_names[n-1]<<" do you want to sell ?"<<endl<<endl;
    cin>>no_of_stocks;

    if(no_of_stocks < 0)
    {
        cout<<"Cannot sell negative number of stocks !"<<endl;
        cout<<"Do you want tot try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }
    
    else if(no_of_stocks == 0)
    {
        cout<<"Cannot sell zero stocks !"<<endl;
        cout<<"Do you want tot try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }
    
    if(no_of_stocks > user.get_my_stock(n-1))
    {
        cout<<"You don't now own that many stocks of "<<stock_names[n-1]<<endl;
        cout<<"Do you want to try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
        
        else
        {
            cout<<"Stock Sale unsuccesful"<<endl<<endl;
            return;
        }
            
        
    }

   sale_amount = no_of_stocks * stock_array[n-1];

    cout<<"No of stocks sold = "<<no_of_stocks<<endl<<endl;
    cout<<"Money earned = "<<sale_amount<<endl<<endl;

    user.sell_my_stock(n, no_of_stocks, sale_amount);
        
    cout<<"Stock sale successful"<<endl<<endl;
    fout<<"S"<<" "<<sale_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();

}

void trade_stocks(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    char a, ans = 'y';
    
    cout<<"********************************************* Stock Trading Mode *********************************************"<<endl<<endl;
    
    while(ans == 'y')
    {
        cout<<"Press \"b\" to buy stocks"<<endl<<"Press \"s\" to sell stocks"<<endl<<"Press any other key to exit Stock Trading Mode"<<endl<<endl;
        cin>>a;
        
        switch(a)
        {
            case 'b':
                buy_stock(user, stock_array, stock_names, day);
                break;
        
            case 's':
                sell_stock(user, stock_array, stock_names, day);
                break;
    
            default:
                cout<<"Invalid input !"<<endl<<endl;
                break;
        }

        cout<<"Do you want to trade stocks again (y/n)";
        cin>>ans;
    }
    
}
