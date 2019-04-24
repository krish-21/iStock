#include <vector>
#include <iostream>
#include <fstream>
#include "investor_class.h"
#include "stock_trading.h"

using namespace std;

bool Buy_Stock(Investor user, vector <double> Stock_Vector)
{
    char ans='y';
    int n;
    double purachse_amount, no_of_stocks;
    ofstream fout;
    fout.open("transaction_records.txt", ios::app);

    if(user.get_wallet_balance() == 0)
    {
        cout << "Insuficient Wallet Balance !" << endl << "Please add money to your wallet"<<endl<<endl;
        return false;
    }

    while(ans=='y')
    {
        cout<<"Which stock do you want to buy ? :   ";
        cin>>n;
        cout<<endl;
        cout<<"How much do you want to spend ? :   ";
        cin>>purachse_amount;

        //no_of_stocks = purachse_amount /  _____________;

        cout<<"No of stocks = "<<no_of_stocks<<endl<<endl;

        if(user.buy_my_stock(n, no_of_stocks))
        {   
            cout<<"Stock purchase successful"<<endl<<endl;
            //fout<<
        }

        else
        {
            cout<<"Stock purchase unsuccessfull";
        }

    }
    
    return true;
        
}

bool Sell_Stock(Investor user, vector <double> Stock_Vector)
{
    if(user.get_net_worth() == 0)
    {
        cout << "You do not own anything valuable to sell !!!" << endl;
        cout << "Please buy some stocks to start selling" << endl << endl;
        return false;
    }

    return true;

}

void trade_stocks(Investor user, vector <double> Stock_Vector)
{
    char a;
    
    cout<<"*************************** Stock Trading Mode ***********************************"<<endl<<endl;
    cout<<"Press \"b\" to buy stocks"<<endl<<"Press \"s\" to sell stocks"<<endl<<"Press any other key to exit Stock Trading Mode"<<endl<<endl;

    while(true)
    {
        switch(a)
        {
            case 'b':
                if(Buy_Stock(user, Stock_Vector))
                    cout<<"Stock purchase successfull !";
                else
                    
                break;
        
            case 's':
                if(Sell_Stock(user, Stock_Vector))
                    cout<<"Stock sale successfull";
                break;
    
            default:
                break;
        }
    }
    
}
