#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "search_data.h"

using namespace std;

struct searchuser   //structure for storing the data from the text file
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
	
	cout<<"You can search on these criteria-"<<endl;  //criteria for searching , we tried to provide as many criteria possible
	cout<<"---------------------------------------"<<endl;
	cout<<"1- Amount Spent"<<endl;  //searching according to amount spent- you enter a value and we search for amount greater than or smaller than that value
	cout<<"2- Number of shares"<<endl; //searching accoring to a particular number of shares
	cout<<"3- Company Name"<<endl; //searching accoring to the name of company
	cout<<"4- Shares Bought"<<endl; //searching accoring to shares bought
	cout<<"5- Shares Sold"<<endl; //searching accoring to shares sold
	cout<<"6- Day"<<endl; //searching accoring to the day of transaction
	cout<<"---------------------------------------"<<endl;
	
	cout<<"7- Exit Transaction History Mode"<<endl<<endl;
	
	cout<<"Choose a value:"<<endl;
	
	int n;
	cin>>n;
	
	while(n<1 || n>7)  //while loop for checking if the value is valid or not
	{
		cout<<endl<<"Invalid Input"<<endl;
		cout<<"Enter Number Again:"<<endl;
		cin>>n;
	}

	ifstream finuser; //opening file of records of user
	finuser.open(filename);
	
	if(finuser.fail())  //if failed to open file, go back to the main function
	{
		cout<<"Unable to open "<<filename<<endl<<endl;
		cout<<"Exiting the Current Mode"<<endl<<endl<<endl<<endl;
		return;
	}
	
	int filelength=0; //for counting length of file
	string line;
	while(getline(finuser,line))
	{
		filelength++; //counting length of file
	}
	
	if(filelength==0) //if filelength is equal to zero, go back to main function
	{
		cout<<"No records found in your file"<<endl<<endl;
		cout<<"Exiting the Current Mode"<<endl<<endl<<endl<<endl;
		return;
	}
	
	finuser.clear();  //going back to the first position of text file for entering data
	finuser.seekg(0, ios::beg);
	
	searchuser * uservalues=new searchuser[filelength];  // creating a dynamic array of type structure searchuser of exact number of lines as the file so that no memory is wasted at all
	int k=0; 
	
	while(finuser>>uservalues[k].c>>uservalues[k].amountspent>>uservalues[k].numberofshares>>uservalues[k].companyname>>uservalues[k].shareprice>>uservalues[k].day)
	{
		k++;  //initiliazing data of user in an array of structure searchuser
	}



// these are commented as we were using while testing the file
//	cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent   "<<"Number of shares   "<<"Company Name   "<<"Share Price   "<<"Day   "<<endl;
//	for(int j=0;j<filelength;j++)
//	{
//		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(15)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)<<uservalues[j].companyname<<left<<setw(14)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
//	}

	finuser.close(); //closing file as soon as data is extracted form it
	
	
	int i;
	if(n==1)  //for searching according to amount spent
	{
		double value_smaller,value_greater;
		int num;
		
		cout<<"1- Greater than equal to the amount spent"<<endl;  //for searching according to values greater than a particular amount
		cout<<"2- Smaller than equal to the amount spent"<<endl;  //for searching according to values smaller than a particular amount
		cout<<"Choose a value:"<<endl;
		cin>>num;
		
		while(num!=1 && num!=2) //while loop for checking if the number is valid
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
			
			while(value_greater<0) //checking if the amount spent is positive
	 		{
	 			cout<<"Value of shares must be positive"<<endl;
	 			cout<<"Enter value of shares again:"<<endl;
	 			cin>>value_greater;
	 		}
	 		
			for(i=0;i<filelength;i++) //for loop for comparing values of the entire arrray 
			{
				if(uservalues[i].amountspent>=value_greater) //printing as soon as a value greater than the amount entered is found with output formatting in columns
				{
					if(counter==0)
					{
						cout<<endl;
						cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
					}
					cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
					<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
					counter++;
				}
			}
			
			if(counter==0) //if no value is found greater than the amount entered then print the message
			{
				cout<<"No shares found"<<endl;
			}
		}
		else if(num==2)
		{
			int counter=0;
			cout<<"Enter Amount spent:"<<endl;  //enter amount for searching values smaller than a particular value
			cin>>value_smaller;
			
			while(value_smaller<0)  // loop for checking if value entered is positive
	 		{ 
	 			cout<<"Value of shares must be positive"<<endl;
	 			cout<<"Enter value of shares again:"<<endl;
	 			cin>>value_smaller;
	 		}
	 		
			for(i=0;i<filelength;i++)
			{
				if(uservalues[i].amountspent<=value_smaller) //printing as soon as a value smaller than the amount entered is found with output formatting in cloumns
				{
					if(counter==0)
					{
						cout<<endl;
						cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
					}
					cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
					<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
					counter++;
				}
			}
			
			if(counter==0) //printing message if no shares found
			{
				cout<<"No shares found"<<endl;
			}
		}
	}
	else if(n==2)  //searching according to a particular number of sharez
	{
		int noshares;
		cout<<"Enter number of shares:"<<endl;
	 	cin>>noshares;
	 	
	 	while(noshares<0) //number of shares must be positive
	 	{
	 		cout<<"Number of shares must be positive"<<endl;
	 		cout<<"Enter number of shares again:"<<endl;
	 		cin>>noshares;
	 	}
	 	
	 	int counter=0;
	 	
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].numberofshares==noshares) //printing as soon as number of shares is equal to the value entered  with output formatting in columns
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)  //if no shares found print message
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==3)  //for searching according to company name
	{
		string cname;
		cout<<"Enter Company Name:"<<endl;
		cin>>cname;
		
		//checking company name without capital or small error
		//if error in company name is there reenter the value
		
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
		
		for(i=0;i<cnamecopy.length();i++) //for entering company name while ignoring case of the character entered
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
			if(uservalues[i].companyname==cname) //printing as soon as the company name is found with output formatting
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==4)  //fpr searching according to shares bought of sold
	{
		int counter=0;
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].c=='B') //printing as soon  as bought shares are found with output formatting
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
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
			if(uservalues[i].c=='S') //printing as soon as sold shares are found with output formatting
			{
			if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}
		
		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}
	else if(n==6) //for searching according to day number of transaction
	{
		int dayno;
		cout<<"Enter Day Number:"<<endl;
		cin>>dayno;
		
		while(dayno<0) //day number must be positive
	 	{
	 		cout<<"Number of the day must be positive"<<endl;
	 		cout<<"Enter number of the day again:"<<endl;
	 		cin>>dayno;
	 	}
	 	
		int counter=0;
		
		for(i=0;i<filelength;i++)
		{
			if(uservalues[i].day==dayno) //printing as day number is same with the number entered by user with output formatting
			{
				if(counter==0)
				{
					cout<<endl;
					cout<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
				}
				cout<<left<<setw(27)<<uservalues[i].c<<left<<setw(18)<<uservalues[i].amountspent<<left<<setw(19)<<uservalues[i].numberofshares
				<<left<<setw(15)<<uservalues[i].companyname<<left<<setw(17)<<uservalues[i].shareprice<<left<<setw(6)<<uservalues[i].day<<endl;
				counter++;
			}
		}

		if(counter==0)
		{
			cout<<"No shares found"<<endl;
		}
	}

	else if(n==7) //exiting and returning back to main function
	{
		cout<<endl<<endl<<"Exiting Transaction History Mode..."<<endl<<endl;
		return;
	}
	delete [] uservalues; //deleting the dynamic array of type structure as soon as its user if over to free memory even during runtime
} 
