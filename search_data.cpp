#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "search_data.h"

using namespace std;

struct searchuser
{
	char c;
	double amountspent;
	int numberofshares;
	string companyname;
	double shareprice;
	int day;
};

void search_records()
{
	string filename = "records.txt";
	//cin>>name;
	//string filename=name+".txt";
	//cout<<filename<<endl;
	
	cout<<"******************************************* Transaction History *******************************************"<<endl<<endl;
	
	cout<<"You can search on these criteria-"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"1- Amount Spent"<<endl;
	cout<<"2- Number of shares"<<endl;
	cout<<"3- Company Name"<<endl;
	cout<<"4- Shares Bought"<<endl;
	cout<<"5- Shares Sold"<<endl;
	cout<<"6- Day"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"7- Exit Transaction History Mode"<<endl<<endl;
	cout<<"Choose a value:"<<endl;
	
	int n;
	cin>>n;
	
	while(n<1 || n>7)
	{
		cout<<endl<<"Invalid Input"<<endl;
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
	
	searchuser * uservalues=new searchuser[filelength];
	int k=0; 
	
	while(finuser>>uservalues[k].c>>uservalues[k].amountspent>>uservalues[k].numberofshares>>uservalues[k].companyname>>uservalues[k].shareprice>>uservalues[k].day)
	{
		k++;
	}
	
//	cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   "<<"Number of shares   "<<"Company Name   "<<"Share Price   "<<"Day   "<<endl;
//	for(int j=0;j<filelength;j++)
//	{
//		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(15)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)<<uservalues[j].companyname<<left<<setw(14)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
//	}

	finuser.close();

	int i;
	if(n==1)
	{
		double value_smaller,value_greater;
		int num;
		
		cout<<"1- Greater than equal to the amount spent"<<endl;
		cout<<"2- Smaller than equal to the amount spent"<<endl;
		cout<<"Choose a value:"<<endl;
		cin>>num;
		
		while(num!=1 && num!=2)
		{
			cout<<"Invalid Choice"<<endl;
			cout<<"Enter Number Again:"<<endl;
			cin>>num;
		}
		
		if(num==1)
		{
			int counter=0;
			cout<<"Enter Amount spent:"<<endl;
			cin>>value_greater;
			
			while(value_greater<0)
	 		{
	 			cout<<"Value of shares must be positive"<<endl;
	 			cout<<"Enter value of shares again:"<<endl;
	 			cin>>value_greater;
	 		}
	 		
			for(i=0;i<filelength;i++)
			{
				if(uservalues[i].amountspent>=value_greater)
				{
					if(counter==0)
					{
						cout<<endl;
						cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
					}
					cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
					<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
					counter++;
				}
			}
			
			if(counter==0)
			{
				cout<<"No shares found"<<endl;
			}
		}
		else if(num==2)
		{
			int counter=0;
			cout<<"Enter Amount spent:"<<endl;
			cin>>value_smaller;
			
			while(value_smaller<0)
	 		{
	 			cout<<"Value of shares must be positive"<<endl;
	 			cout<<"Enter value of shares again:"<<endl;
	 			cin>>value_smaller;
	 		}
	 		
			for(i=0;i<filelength;i++)
			{
				if(uservalues[i].amountspent<=value_smaller)
				{
					if(counter==0)
					{
						cout<<endl;
						cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
					}
					cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
					<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
					counter++;
				}
			}
			
			if(counter==0)
			{
				cout<<"No shares found"<<endl;
			}
		}
	}
	else if(n==2)
	{
		int noshares;
		cout<<"Enter number of shares:"<<endl;
	 	cin>>noshares;
	 	
	 	while(noshares<0)
	 	{
	 		cout<<"Number of shares must be positive"<<endl;
	 		cout<<"Enter number of shares again:"<<endl;
	 		cin>>noshares;
	 	}
	 	
	 	int counter=0;
	 	
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].numberofshares==noshares)
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $"<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==3)
	{
		string cname;
		cout<<"Enter Company Name:"<<endl;
		cin>>cname;
		
		while(cname!="Google" && cname!="Apple" && cname!="Microsoft" && cname!="Facebook" && cname!="Amazon" 
		&& cname!="google" && cname!="apple" && cname!="microsoft" && cname!="facebook" && cname!="amazon" && 
		cname!="GOOGLE" && cname!="APPLE" && cname!="MICROSOFT" && cname!="FACEBOOK" && cname!="AMAZON")
		{
			cout<<"Invalid Company Name"<<endl;
			cout<<"Enter Company Name again:"<<endl;
			cin>>cname;
		}
		
		string cnamecopy=cname;
		cname="";
		int counter=0;
		
		for(i=0;i<cnamecopy.length();i++)
		{
			char x=cnamecopy[i];
			if(i==0)
			{
				cname+=(toupper(x));
			}
			else
			{
				cname+=(tolower(x));
			}
		}
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].companyname==cname)
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==4)
	{
		int counter=0;
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].c=='B')
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==5)
	{
		int counter=0;
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].c=='S')
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==6)
	{
		int dayno;
		cout<<"Enter Day Number:"<<endl;
		cin>>dayno;
		
		while(dayno<0)
	 	{
	 		cout<<"Number of the day must be positive"<<endl;
	 		cout<<"Enter number of the day again:"<<endl;
	 		cin>>dayno;
	 	}
	 	
		int counter=0;
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].day==dayno)
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   $ "<<"Number of shares   "<<"Company Name   "<<"Share Price   $ "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(15)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(14)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}

	else if(n==7)
	{
		cout<<endl<<endl<<"Exiting Transaction History Mode..."<<endl<<endl;
		return;
	}
	delete [] uservalues;
}
