#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

#include "stock_manipulation.h"

using namespace std;

void share_manipulation()
{
	string companyname[5]={"Alphabet","Apple","Microsoft","Facebook","Amazon"}; //to remember order of company name in text file
	
	double * shareprice=new double[5](); //dynamic array for storing initial stock prices
	
	double * changedshareprice=new double[5](); //dynamic array for storing randomly changed stock prices
	
	ifstream finshares;  //for opening files containing share prices
	ofstream foutshares; //for closing files containing share prices
	
	finshares.open("shares.txt");
	
	if(finshares.fail()) //exit if failed to open shares.txt
	{
		cout<<endl<<"Failed to open shares.txt"<<endl;
		cout<<"Exiting Current Mode"<<endl<<endl;
		return;
	}
	
	finshares.seekg(-36,ios_base::end);  //for getting last 5 values of shares
	
	for(int i=0;i<5;i++)
	{
		finshares>>shareprice[i]; //storing last 5 share values in an array
	}

	finshares.close();

	srand(time(NULL)); //initializing time of random variable to NULL everytime so random does not give same value 
	
	double random[]={1,-1,2,3,-1,-3,1,5,-4,-1,-2,2,-5,4,-3,-2,1,-1,3,-2,1,2}; //array for random fluctuations of share prices according to probability- more 1s and less 5s in the array
	
	for(int i=0;i<5;i++)
	{
		
		int valueofrandom=rand()%22; //for randomly choosing values for change percent of share price
		changedshareprice[i]=shareprice[i]+((random[valueofrandom]/100)*shareprice[i]); //changing each share price randomly 
		
		if(i==0) //if conditions for controlling  the number of characters after random variation does not go below or above 7 characters- 4 digits, 1 point and 2 decimal points
		{
			if(changedshareprice[0]<1000)
			{
				changedshareprice[0]=shareprice[0]+(0.1*shareprice[0]);
			}
			if(changedshareprice[0]>9999)
			{
				changedshareprice[0]=shareprice[0]-(0.1*shareprice[0]);
			}
		}
		
		if(i==1) //if conditions for controlling  the number of characters after random variation does not go below or above 6 characters- 3 digits, 1 point and 2 decimal points
		{
			if(changedshareprice[1]<100)
			{
				changedshareprice[1]=shareprice[1]+(0.1*shareprice[1]);
			}
			if(changedshareprice[1]>999)
			{
				changedshareprice[1]=shareprice[1]-(0.1*shareprice[1]);
			}
		}
		
		if(i==2) //if conditions for controlling  the number of characters after random variation does not go below or above 6 characters- 3 digits, 1 point and 2 decimal points
		{
			if(changedshareprice[2]<100)
			{
				changedshareprice[2]=shareprice[2]+(0.1*shareprice[2]);
			}
			if(changedshareprice[2]>999)
			{	
				changedshareprice[2]=shareprice[2]-(0.1*shareprice[2]);
			}
		}
		
		if(i==3) //if conditions for controlling  the number of characters after random variation does not go below or above 6 characters- 3 digits, 1 point and 2 decimal points
		{
			if(changedshareprice[3]<100)
			{
				changedshareprice[3]=shareprice[3]+(0.1*shareprice[3]);
			}
			if(changedshareprice[3]>999)
			{
				changedshareprice[3]=shareprice[3]-(0.1*shareprice[3]);
			}
		}
		
		if(i==4)//if conditions for controlling  the number of characters after random variation does not go below or above 7 characters- 4 digits, 1 point and 2 decimal points
		{
			if(changedshareprice[4]<1000)
			{
				changedshareprice[4]=shareprice[4]+(0.1*shareprice[4]);
			}
			if(changedshareprice[4]>9999)
			{
				changedshareprice[4]=shareprice[4]-(0.1*shareprice[4]);
			}
		}
		
	}
	delete [] shareprice; //deleting dynamic array as soon as its function is over to free memory
	foutshares.open("shares.txt",ios::app); //for writing new share values in a text file
	if(foutshares.fail()) // if failed to open file, return to main function
	{
		cout<<"Unable to open shares.txt"<<endl;
		cout<<"Exiting Current Mode"<<endl<<endl;
		return;
	}
	foutshares<<endl;
	for(int i=0;i<5;i++) //for writing new values in the text file
	{
		foutshares<<fixed<<showpoint<<setprecision(2)<<changedshareprice[i]; //fixing number of decimal places to 2 digits
		if(i<4)
		{
			foutshares<<" "; //for space after each value
		}
	}
	foutshares.close(); //closing file after adding values
	delete [] changedshareprice; // deleting dynamic array after using it
}

void read_shares_into_array(double stock_array[5]) //reading values to the array of class
{
	double stock;
	ifstream fin;
	
	fin.open("shares.txt");

	if(fin.fail())
	{
		cout<<"Unable to open shares.txt"<<endl;
		cout<<"Exiting Current Mode"<<endl<<endl;
		return;
	}

	fin.seekg(-36,ios_base::end); //going to place for taking last 5 values

	for(int i=0; i<5; ++i)
	{
		fin>>stock;
		stock_array[i]=stock; //adding values to the array
	}
	fin.close();
}
