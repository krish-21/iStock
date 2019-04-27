#include <iostream>
#include <fstream>

#include "investor_class.h"
#include "stock_trading.h"
#include "money_management.h"

using namespace std;

void buy_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    
    if(user.get_wallet_balance() == 0)
    {
        cout<<endl<<"Insuficient Wallet Balance !"<<endl<<"Please add money to your wallet"<<endl<<endl;
        return;
    }

    int n;
    double purchase_amount, no_of_stocks;
    char ans = 'y';

    ofstream fout;
    fout.open("records.txt", ios::app);

    if(fout.fail())
	{
		cout<<endl<<"Unable to open records.txt"<<endl<<endl;
        cout<<"Exiting the Current Mode"<<endl<<endl;
        return;
	}

    label1:

    cout<<endl<<endl;

    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	for(int i=0; i<5; ++i)
	{
		cout<<i+1<<". "<<stock_names[i]<<" : "<<stock_array[i]<<endl;
	}

    cout<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    user.print_my_stocks();
    cout<<endl<<endl;

    cout<<"                                                      Wallet Balance = $ "<<user.get_wallet_balance()<<endl<<endl;
    cout<<"Which stock do you want to buy ?"<<endl<<endl;
    cout<<"Enter the S.No of the corresponding Stock (1-5) :  ";
    cin>>n;

    if(n<1 || n>5)
    {
        cout<<endl<<"Invalid input"<<endl<<endl;
        cout<<"Do you want to try again (y/n) ?  ";
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
        else
        {
            cout<<endl<<"Exiting Buying Mode..."<<endl<<endl;
            return;
        }
    
    }

    cout<<endl;

    cout<<"How many stocks of "<<stock_names[n-1]<<" do you want to buy ?  ";
    cin>>no_of_stocks;

    if(no_of_stocks < 0)
    {
        cout<<endl<<"Cannot buy negative number of stocks !"<<endl<<endl;
        cout<<"Do you want to try again (y/n) ?  ";
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<endl<<"Exiting Buying Mode..."<<endl<<endl;
            return;
        }
    }
    
    else if(no_of_stocks == 0)
    {
        cout<<endl<<"Cannot buy zero stocks !"<<endl<<endl;
        cout<<"Do you want to try again (y/n) ?  ";
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<endl<<"Exiting Buying Mode..."<<endl<<endl;
            return;
        }
    }
    
    purchase_amount = no_of_stocks * stock_array[n-1];

    if(purchase_amount > user.get_wallet_balance())
    {
        cout<<endl<<"Insufficient Wallet Balance !"<<endl<<endl;
        cout<<"Do you want to try again (y/n) ?  ";
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<endl<<"Exiting Buying Mode..."<<endl<<endl;
            return;
        }
    }

    cout<<endl<<"No of stocks bought   "<<"=  "<<no_of_stocks<<endl;
    cout<<"Amount Spent          "<<"=  $ "<<purchase_amount<<endl<<endl;

    user.buy_my_stock(n, no_of_stocks, purchase_amount);
        
    cout<<endl<<"Purchase of "<<stock_names[n-1]<<" stocks successful"<<endl<<endl<<endl;
    fout<<"B"<<" "<<purchase_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();
        
}

void sell_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    if(user.get_net_worth() == 0)
    {
        cout<<endl<<"You do not own anything valuable to sell !!!"<<endl<<endl;
        cout<<"Please increase your networth to start selling"<<endl<<endl;
        return;
    }

    char ans;
    int n;
    double sale_amount, no_of_stocks;

    ofstream fout;
    fout.open("records.txt", ios::app);

    if(fout.fail())
	{
		cout<<endl<<"Unable to open records.txt"<<endl<<endl;
        cout<<"Exiting current mode";
        return;
	}

    label1:
    
    cout<<endl<<endl;

    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	for(int i=0; i<5; ++i)
	{
		cout<<i+1<<". "<<stock_names[i]<<" : "<<stock_array[i]<<endl;
	}

    cout<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    user.print_my_stocks();
    cout<<endl<<endl;

    cout<<"                                                      Wallet Balance = $ "<<user.get_wallet_balance()<<endl<<endl;
    cout<<"Which stock do you want to sell ? :   ";
    cin>>n;
    cout<<endl;
    cout<<"How many stocks of "<<stock_names[n-1]<<" do you want to sell ?"<<endl<<endl;
    cin>>no_of_stocks;

    if(no_of_stocks < 0)
    {
        cout<<endl<<"Cannot sell negative number of stocks !"<<endl;
        cout<<"Do you want to try again (y/n) ?"<<endl;
        cin>>ans;

        if(ans == 'y')
            goto label1;
    
         else
        {
            cout<<endl<<"Exiting Selling Mode..."<<endl<<endl;
            return;
        }
    }
    
    else if(no_of_stocks == 0)
    {
        cout<<endl<<"Cannot sell zero stocks !"<<endl;
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
    
    if(no_of_stocks > user.get_my_stock(n-1))
    {
        cout<<endl<<"You don't now own that many stocks of "<<stock_names[n-1]<<endl;
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

    cout<<endl<<"No of stocks sold = "<<no_of_stocks<<endl<<endl;
    cout<<"Money earned =  $ "<<sale_amount<<endl<<endl;

    user.sell_my_stock(n, no_of_stocks, sale_amount);
        
    cout<<endl<<"Stock sale successful"<<endl<<endl;
    fout<<"S"<<" "<<sale_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();

}

void trade_stocks(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    char a, ans = 'y';
    
    cout<<"********************************************* Stock Trading Mode *********************************************"<<endl<<endl;
    
    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	for(int i=0; i<5; ++i)
	{
		cout<<i+1<<". "<<stock_names[i]<<" : "<<stock_array[i]<<endl;
	}

    cout<<endl<<endl;

    while(ans == 'y')
    {
        cout<<"Press \"b\" to buy stocks"<<endl;
        cout<<"Press \"s\" to sell stocks"<<endl;
        cout<<"Press \"e\" to exit Stock Trading Mode"<<endl<<endl;
        cout<<"Input - ";
        cin>>a;
        
        switch(a)
        {
            case 'b':
                buy_stock(user, stock_array, stock_names, day);
                calculate_net_worth(user, stock_array);;
                break;
        
            case 's':
                sell_stock(user, stock_array, stock_names, day);
                calculate_net_worth(user, stock_array);
                break;
    
            case 'e':
            cout<<"Exiting Stock Trading Mode"<<endl<<endl;
            return;
            
            default:
                cout<<"Invalid input !"<<endl<<endl;
                break;
        }

        cout<<"Do you want to trade stocks again (y/n) ?  ";
        cin>>ans;
        cout<<endl<<endl;
    }

    cout<<endl<<endl;
    cout<<"Exiting Current Mode"<<endl<<endl;
    
}
