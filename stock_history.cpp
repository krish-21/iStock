#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>

#include "stock_history.h"

using namespace std;

void print_history(string stock_names[5])
{
    int sno, i, days, max_days=0;
    char ans;
    double temp_stock_value;

    //vector for each company's stock history
    vector <double> alphabet_vector;
    vector <double> apple_vector;
    vector <double> microsoft_vector;
    vector <double> facebook_vector;
    vector <double> amazon_vector;

    ifstream fin;
    fin.open("shares.txt");

    //if shares.txt cannot be opened, return to dashboard
    if(fin.fail())
    {
        cout<<"Unable to open shares.txt"<<endl;
        cout<<"Exiting Current Mode"<<endl<<endl;
        return;
    }

    //read the company stocks from shares.txt and store them in the vector
    //while loop till end of file has been reached
    while(!fin.eof())
    {
        cout<<"in while loop"<<endl<<endl;
                    
        fin>>temp_stock_value;
        alphabet_vector.push_back(temp_stock_value);

        fin>>temp_stock_value;
        apple_vector.push_back(temp_stock_value);

        fin>>temp_stock_value;
        microsoft_vector.push_back(temp_stock_value);

        fin>>temp_stock_value;
        facebook_vector.push_back(temp_stock_value);

        fin>>temp_stock_value;
        amazon_vector.push_back(temp_stock_value);

        ++max_days;

        cout<<endl;
    }

    label1:
    
    cout<<"Please choose the S.No of the company of which you wish to see the stock history :"<<endl<<endl;

    cout<<"1. Alphabet"<<endl;
    cout<<"2. Apple"<<endl;
    cout<<"3. Microsoft"<<endl;
    cout<<"4. Facebook"<<endl;
    cout<<"5. Amazon"<<endl<<endl;

    cout<<"SNo : ";
    cin>>sno;
    cout<<endl<<endl;

    //to check if input is a valid number
    if(sno<1 || sno>5)
    {
        cout<<"Invalid input !"<<endl;
        cout<<"Do you want to try again (y/n) ? ";
        cin>>ans;
        cout<<endl<<endl;

        if(ans=='y')
        {
            goto label1;
        }
        
        else
        {
            cout<<"Exiting Stock History Mode"<<endl<<endl;
            return;
        }
    }

    cout<<"How many days back do you want the Stock History to start from ? :                     No of days passed = "<<max_days<<endl<<endl;
    cout<<"Days back - ";
    cin>>days;

    //days back cannot be ahead
    if(days<=0)
    {
        cout<<"Invalid input !"<<endl;
        cout<<"Do you want to try again (y/n) ? ";
        cin>>ans;
        cout<<endl<<endl;

        if(ans=='y')
        {
            goto label1;
        }
        
        else
        {
            cout<<"Exiting Stock History Mode"<<endl<<endl;
            return;
        }
    }

    //days back cannot be greater than the days passed
    if(days>max_days)
    {
        cout<<"Invalid Input ! "<<endl;
        cout<<"Cannot go print more than "<<max_days<<endl<<endl;
        cout<<"Do you want to try again (y/n) ? ";
        cin>>ans;
        cout<<endl<<endl;

        if(ans=='y')
        {
            goto label1;
        }
        
        else
        {
            cout<<"Exiting Stock History Mode"<<endl<<endl;
            return;
        }
    }

    //switch case for each of the different companies
    switch(sno)
    {
        case 1:

            cout<<"Alphabet Stock Price History : "<<endl<<endl;
            for(i=alphabet_vector.size()-days; i<alphabet_vector.size(); ++i)
                cout<<alphabet_vector[i]<<"  ";
            break;

        case 2:

            cout<<"Apple Stock Price History : "<<endl<<endl;
            for(i=apple_vector.size()-days; i<apple_vector.size(); ++i)
                cout<<apple_vector[i]<<"  ";
            break;

        case 3:

            cout<<"Microsoft Stock Price History : "<<endl<<endl;
            for(i=microsoft_vector.size()-days; i<microsoft_vector.size(); ++i)
                cout<<microsoft_vector[i]<<"  ";
            break;

        case 4:

            cout<<"Facebook Stock Price History : "<<endl<<endl;
            for(i=facebook_vector.size()-days; i<facebook_vector.size(); ++i)
                cout<<facebook_vector[i]<<"  ";
            break;

        case 5:

            cout<<"Amazon Stock Price History : "<<endl<<endl;
            for(i=amazon_vector.size()-days; i<amazon_vector.size(); ++i)
                cout<<amazon_vector[i]<<"  ";
            break;
    }

    cout<<endl<<endl;
    cout<<"Do you want to look at Stock History again (y/n) ? ";
    
    cin>>ans;

    //check if user wants to see the history again
    if(ans=='y')
        {
            goto label1;
        }
        
        //if no, return to the dashboard
        else
        {
            cout<<endl<<endl;
            cout<<"Exiting Stock History Mode"<<endl<<endl;
            return;
        }
    fin.close();
}
