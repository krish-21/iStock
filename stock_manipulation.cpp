#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

#include "stock_manipulation.h"

using namespace std;

void share_manipulation()
{
	string companyname[5]={"Google","Apple","Microsoft","Facebook","Amazon"};
	
	double * shareprice=new double[5]();
	
	double * changedshareprice=new double[5]();
	
	ifstream finshares;
	ofstream foutshares;
	
	finshares.open("shares.txt");
	
	if(finshares.fail())
	{
		cout<<endl<<"Failed to open shares.txt"<<endl;
		exit(0);
	}
	
	finshares.seekg(-36,ios_base::end);
	
	for(int i=0;i<5;i++)
	{
		finshares>>shareprice[i];
	}

	finshares.close();

	srand(time(NULL));
	
	double random[]={1,-1,2,3,-1,-3,1,5,-4,-1,-2,2,-5,4,-3,-2,1,-1,3,-2,1,2};
	
	for(int i=0;i<5;i++)
	{
		
		int valueofrandom=rand()%22;
		changedshareprice[i]=shareprice[i]+((random[valueofrandom]/100)*shareprice[i]);
		
		if(i==0)
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
		
		if(i==1)
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
		
		if(i==2)
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
		
		if(i==3)
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
		
		if(i==4)
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
	delete [] shareprice;
	foutshares.open("shares.txt",ios::app);
	if(foutshares.fail())
	{
		cout<<"Unable to open shares.txt"<<endl;
		exit(1);
	}
	foutshares<<endl;
	for(int i=0;i<5;i++)
	{
		foutshares<<fixed<<showpoint<<setprecision(2)<<changedshareprice[i];
		if(i<4)
		{
			foutshares<<" ";
		}
	}
	foutshares.close();
	delete [] changedshareprice;
}

void read_shares_into_array(double stock_array[5])
{
	double stock;
	ifstream fin;
	
	fin.open("shares.txt");

	if(fin.fail())
	{
		cout<<"Unable to open shares.txt"<<endl;
		exit(1);
	}

	fin.seekg(-36,ios_base::end);

	for(int i=0; i<5; ++i)
	{
		fin>>stock;
		stock_array[i]=stock;
	}
}
