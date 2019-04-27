#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "sortuser.h"
#include "sort.h"

using namespace std;

void sorting()
{

	string filename="records.txt";
	
	cout<<"You can sort on these criteria-"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"1- Amount Spent - Ascending order "<<endl;
	cout<<"2- Amount Spent - Descending order "<<endl;
	cout<<"3- Number of shares - Ascending order"<<endl;
	cout<<"4- Number of shares - Descending order"<<endl;
	cout<<"5- Share Price - Ascending order"<<endl;
	cout<<"6- Share Price - Descending order"<<endl;
	cout<<"7- Company Name in alphabetical order"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"8- Exit Current Mode"<<endl;
	cout<<"Choose a value:"<<endl;

	int n;
	cin>>n;
	
	while(n<1 || n>8)
	{
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Number Again:"<<endl;
		cin>>n;
	}

	ifstream finuser;
	finuser.open(filename);
	
	if(finuser.fail())
	{
		cout<<"Unable to open "<<filename<<endl;
		exit(1);
	}
	
	int filelength=0;
	string line;
	
	while(getline(finuser,line))
	{
		filelength++;
	}
	
	if(filelength==1)
	{
		cout<<"No records found in your file";
		exit(1);
	}
	
	finuser.clear();
	finuser.seekg(0, ios::beg);
	
	sortuser * uservalues=new sortuser[filelength];
	int k=0; 
	
	while(finuser>>uservalues[k].c>>uservalues[k].amountspent>>uservalues[k].numberofshares>>uservalues[k].companyname>>uservalues[k].shareprice>>uservalues[k].day)
	{
		k++;
	}
	
	finuser.close();
	if(n==1)
	{
		sortamount(uservalues,filelength);
		print(uservalues,filelength);
	}
	else if(n==2)
	{
		sortamount(uservalues,filelength);
		print_reverse(uservalues,filelength);
	}
	else if(n==3)
	{
		sortnumberofshares(uservalues,filelength);
		print(uservalues,filelength);
	}
	else if(n==4)
	{
		sortnumberofshares(uservalues,filelength);
		print_reverse(uservalues,filelength);
	}
	else if(n==5)
	{
		sortshareprice(uservalues,filelength);
		print(uservalues,filelength);
	}
	else if(n==6)
	{
		sortshareprice(uservalues,filelength);
		print_reverse(uservalues,filelength);
	}
	else if(n==7)
	{
		int i,j,min;
		
		for(i=0;i<(filelength-1);i++)
		{
			int min=i;
			
			for(j=i+1;j<filelength;j++)
			{
				if(uservalues[j].companyname<uservalues[min].companyname)
				{
					min=j;
				}
			}
			
			char swap1=uservalues[min].c;
			uservalues[min].c=uservalues[i].c;
			uservalues[i].c=swap1;
			double swap2=uservalues[min].amountspent;
			uservalues[min].amountspent=uservalues[i].amountspent;
			uservalues[i].amountspent=swap2;
			int swap3=uservalues[min].numberofshares;
			uservalues[min].numberofshares=uservalues[i].numberofshares;
			uservalues[i].numberofshares=swap3;	
			string swap4=uservalues[min].companyname;
			uservalues[min].companyname=uservalues[i].companyname;
			uservalues[i].companyname=swap4;
			double swap5=uservalues[min].shareprice;
			uservalues[min].shareprice=uservalues[i].shareprice;
			uservalues[i].shareprice=swap5;
			int swap6=uservalues[min].day;
			uservalues[min].day=uservalues[i].day;
			uservalues[i].day=swap6;
		}
		print(uservalues,filelength);
	}
	else if(n==8)
	{
		delete [] uservalues;
		cout<<"Exiting Current Mode"<<endl<<endl;
		return;
	}
	delete [] uservalues;
}

void sortamount(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++)
	{
		int min=i;
		for(j=i+1;j<length;j++)
		{
			if(uservalues[j].amountspent<uservalues[min].amountspent)
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;
		uservalues[min].c=uservalues[i].c;
		uservalues[i].c=swap1;
		double swap2=uservalues[min].amountspent;
		uservalues[min].amountspent=uservalues[i].amountspent;
		uservalues[i].amountspent=swap2;
		int swap3=uservalues[min].numberofshares;
		uservalues[min].numberofshares=uservalues[i].numberofshares;
		uservalues[i].numberofshares=swap3;
		string swap4=uservalues[min].companyname;
		uservalues[min].companyname=uservalues[i].companyname;
		uservalues[i].companyname=swap4;
		double swap5=uservalues[min].shareprice;
		uservalues[min].shareprice=uservalues[i].shareprice;
		uservalues[i].shareprice=swap5;
		int swap6=uservalues[min].day;
		uservalues[min].day=uservalues[i].day;
		uservalues[i].day=swap6;
	}
}

void sortnumberofshares(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++)
	{
		int min=i;
		for(j=i+1;j<length;j++)
		{
			if(uservalues[j].numberofshares<uservalues[min].numberofshares)
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;
		uservalues[min].c=uservalues[i].c;
		uservalues[i].c=swap1;
		double swap2=uservalues[min].amountspent;
		uservalues[min].amountspent=uservalues[i].amountspent;
		uservalues[i].amountspent=swap2;
		int swap3=uservalues[min].numberofshares;
		uservalues[min].numberofshares=uservalues[i].numberofshares;
		uservalues[i].numberofshares=swap3;
		string swap4=uservalues[min].companyname;
		uservalues[min].companyname=uservalues[i].companyname;
		uservalues[i].companyname=swap4;
		double swap5=uservalues[min].shareprice;
		uservalues[min].shareprice=uservalues[i].shareprice;
		uservalues[i].shareprice=swap5;
		int swap6=uservalues[min].day;
		uservalues[min].day=uservalues[i].day;
		uservalues[i].day=swap6;
	}
}	
			
void sortshareprice(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++)
	{
		int min=i;
		for(j=i+1;j<length;j++)
		{
			if(uservalues[j].shareprice<uservalues[min].shareprice)
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;
		uservalues[min].c=uservalues[i].c;
		uservalues[i].c=swap1;
		double swap2=uservalues[min].amountspent;
		uservalues[min].amountspent=uservalues[i].amountspent;
		uservalues[i].amountspent=swap2;
		int swap3=uservalues[min].numberofshares;
		uservalues[min].numberofshares=uservalues[i].numberofshares;
		uservalues[i].numberofshares=swap3;
		string swap4=uservalues[min].companyname;
		uservalues[min].companyname=uservalues[i].companyname;
		uservalues[i].companyname=swap4;
		double swap5=uservalues[min].shareprice;
		uservalues[min].shareprice=uservalues[i].shareprice;
		uservalues[i].shareprice=swap5;
		int swap6=uservalues[min].day;
		uservalues[min].day=uservalues[i].day;
		uservalues[i].day=swap6;
	}
}

void print(sortuser uservalues[],int filelength)
{
	cout<<endl<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
	for(int j=0;j<filelength;j++)
	{
		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(18)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)
		<<uservalues[j].companyname<<left<<setw(17)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
	}
}

void print_reverse(sortuser uservalues[],int filelength)
{
	cout<<endl<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
	for(int j=(filelength-1);j>=0;j--)
	{
		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(18)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)
		<<uservalues[j].companyname<<left<<setw(17)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
	}
}

