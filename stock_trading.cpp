#include <iostream>
#include <fstream>
#include <string>

#include "investor_class.h"
#include "stock_trading.h"
#include "money_management.h"

using namespace std;

void buy_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    
    //if User's wallet balance is zero, return to the dashboard
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

    //if records.txt cannot be opened, return to dashboard
    if(fout.fail())
	{
		cout<<endl<<"Unable to open records.txt"<<endl<<endl;
        cout<<"Exiting the Current Mode"<<endl<<endl;
        return;
	}

    label1:

    cout<<endl<<endl;

    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	//print the current market value of the stocks
    for(int i=0; i<5; ++i)
	{
		cout<<i+1<<". "<<stock_names[i]<<" : "<<stock_array[i]<<endl;
	}

    cout<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    //invoke the member function of the class Investor to print the stocks owned by the User
    user.print_my_stocks();
    cout<<endl<<endl;

    cout<<"                                                      Wallet Balance = $ "<<user.get_wallet_balance()<<endl<<endl;
    cout<<"Which stock do you want to buy ?"<<endl<<endl;
    cout<<"Enter the S.No of the corresponding Stock (1-5) :  ";
    cin>>n;

    //check if the serial number entered by the user are valid numbers
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

    //no of stocks to be bought cannot be negative
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
    
    //no of stocks to be bought cannot be zero
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
    
    //calculate the purchase amount
    purchase_amount = no_of_stocks * stock_array[n-1];

    //purchase amount cannot exceed the user's  waller balance
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

    //invoke the member function of thr class Investor to manipulate the stocks owned & wallet balance
    user.buy_my_stock(n, no_of_stocks, purchase_amount);
        
    cout<<endl<<"Purchase of "<<stock_names[n-1]<<" stocks successful"<<endl<<endl<<endl;

    //write a transaction record in records.txt
    fout<<"B"<<" "<<purchase_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();
        
}

void sell_stock(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    //if User's net worth is zero, no sale can be made
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

    //if records.txt cannot be opened, return to dashboard
    if(fout.fail())
	{
		cout<<endl<<"Unable to open records.txt"<<endl<<endl;
        cout<<"Exiting current mode";
        return;
	}

    label1:
    
    cout<<endl<<endl;

    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	//print the current market value of the stocks
    for(int i=0; i<5; ++i)
	{
		cout<<i+1<<". "<<stock_names[i]<<" : "<<stock_array[i]<<endl;
	}

    cout<<endl<<endl;

    cout<<"Stocks owned : "<<endl<<endl;
    
    //invoke the member function of the class Investor to print the stocks owned by the User
    user.print_my_stocks();
    cout<<endl<<endl;

    cout<<"                                                      Wallet Balance = $ "<<user.get_wallet_balance()<<endl<<endl;
    cout<<"Which stock do you want to sell ? :   ";
    cin>>n;
    cout<<endl;

    //check if the serial number entered by the user are valid numbers
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

    
    cout<<"How many stocks of "<<stock_names[n-1]<<" do you want to sell ?"<<endl<<endl;
    cin>>no_of_stocks;

    //no of stocks to be sold cannot be negative
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
    
    //no of stocks to be sold cannot be zero
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
    
    //User cannot sell more stocks than the User owns
    if(no_of_stocks > user.get_my_stock(n))
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

   //calculate the sale amount
   sale_amount = no_of_stocks * stock_array[n-1];

    cout<<endl<<"No of stocks sold = "<<no_of_stocks<<endl<<endl;
    cout<<"Money earned =  $ "<<sale_amount<<endl<<endl;

    //invoke the member function of the class Investor to manipulate the stocks owned & wallet balance
    user.sell_my_stock(n, no_of_stocks, sale_amount);
        
    cout<<endl<<"Stock sale successful"<<endl<<endl;

    //write a transaction record in records.txt
    fout<<"S"<<" "<<sale_amount<<" "<<no_of_stocks<<" "<<stock_names[n-1]<<" "<<stock_array[n-1]<<" "<<day<<endl;

    fout.close();

}

void trade_stocks(Investor &user, double stock_array[5], string stock_names[5], int day)
{
    char a, ans = 'y';
    
    cout<<"********************************************* Stock Trading Mode *********************************************"<<endl<<endl;
    
    cout<<"Current Market Value of Stocks : "<<endl<<endl;

	//print the current market value of the stocks
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
        
        //switch case for Users action
        switch(a)
        {
            case 'b':
        
                //function to buy stocks
                buy_stock(user, stock_array, stock_names, day);

                //change the net worth after the purchase
                calculate_net_worth(user, stock_array);;
                break;
        
            case 's':

                //function to sell stocks
                sell_stock(user, stock_array, stock_names, day);

                //change the net worth after the sale
                calculate_net_worth(user, stock_array);
                break;
    
            case 'e':

                //action to exit the Stock Trading mode
                cout<<"Exiting Stock Trading Mode"<<endl<<endl;
                return;
            
            default:
                
                cout<<"Invalid input !"<<endl<<endl;
                break;
        }

        //after intended action, ask the User if they want to trade stocks again
        cout<<"Do you want to trade stocks again (y/n) ?  ";
        cin>>ans;
        cout<<endl<<endl;
    }

    cout<<endl<<endl;
    cout<<"Exiting Current Mode"<<endl<<endl;
    
}
