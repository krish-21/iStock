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
	
	cout<<"You can sort on these criteria-"<<endl;  //critera for sorting 
	cout<<"---------------------------------------"<<endl;
	cout<<"1- Amount Spent - Ascending order "<<endl; //sorting according to amount spent
	cout<<"2- Amount Spent - Descending order "<<endl; //sorting according to amount spent
	cout<<"3- Number of shares - Ascending order"<<endl; //sorting according to number of shares
	cout<<"4- Number of shares - Descending order"<<endl; //sorting according to number of shares
	cout<<"5- Share Price - Ascending order"<<endl; //sorting according to share price
	cout<<"6- Share Price - Descending order"<<endl; //sorting according to share price
	cout<<"7- Company Name in alphabetical order"<<endl; //soring lexicographically
	cout<<"---------------------------------------"<<endl;
	cout<<"8- Exit Current Mode"<<endl;
	cout<<"Choose a value:"<<endl;

	int n;
	cin>>n;
	
	while(n<1 || n>8) //while loop if user enters an invalid value
	{
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Number Again:"<<endl;
		cin>>n;
	}

	ifstream finuser; // opening file 
	finuser.open(filename);
	
	if(finuser.fail())     //returning tio main function if unable to open file
	{
		cout<<"Unable to open "<<filename<<endl;
		cout<<"Exiting the Current Mode"<<endl<<endl<<endl<<endl;
		return;
	}
	
	int filelength=0; //for counting filelength
	string line; //for entering file
	
	while(getline(finuser,line)) //counting number of lines in each file
	{
		filelength++;
	}
	
	if(filelength==0) //if no lines in file then return to main function
	{
		cout<<"No records found in your file"<<endl<<endl;
		cout<<"Exiting the Current Mode"<<endl<<endl<<endl<<endl;
		return;
	}
	
	finuser.clear(); //returning to first character of the text file
	finuser.seekg(0, ios::beg); //for returning to first character of the file
	
	sortuser * uservalues=new sortuser[filelength]; //creating a dynamic array of struct user of exact number of lines in the text file so that no memory is wasted at all
	int k=0; //for initializing
	
	while(finuser>>uservalues[k].c>>uservalues[k].amountspent>>uservalues[k].numberofshares>>uservalues[k].companyname>>uservalues[k].shareprice>>uservalues[k].day)
	{
		k++; //initiliazing all values in a dynamic array of type structure sortuser
	}
	
	finuser.close(); //closing file as soon as data from file has been extracted
	if(n==1) //using function to sort
	{
		sortamount(uservalues,filelength); //using function to sort according to amount spent
		print(uservalues,filelength); //using print function to print the sorted values
	}
	else if(n==2) //using function to sort
	{
		sortamount(uservalues,filelength); //using function to sort according to amount spent
		print_reverse(uservalues,filelength); //using print function to print the sorted values in reverse order
	}
	else if(n==3) //using function to sort
	{
		sortnumberofshares(uservalues,filelength); //using function to sort according to number of shares
		print(uservalues,filelength); //using print function to print the sorted values
	}
	else if(n==4) //using function to sort
	{
		sortnumberofshares(uservalues,filelength); //using function to sort according to number of shares
		print_reverse(uservalues,filelength); //using print function to print the sorted values in reverse order
	}
	else if(n==5) //using function to sort
	{
		sortshareprice(uservalues,filelength); //using function to sort according to share price
		print(uservalues,filelength); //using print function to print the sorted values
	} 
	else if(n==6) //using function to sort
	{
		sortshareprice(uservalues,filelength); //using function to sort according to share price
		print_reverse(uservalues,filelength); //using print function to print the sorted values in reverse order
	}
	else if(n==7) //using function to sort lexicographically
	{
		int i,j,min;
		
		for(i=0;i<(filelength-1);i++)  //selection sort as it is quite efficient
		{
			int min=i;
			
			for(j=i+1;j<filelength;j++)
			{
				if(uservalues[j].companyname<uservalues[min].companyname) //for comparing name of companies lexicographically
				{
					min=j;
				}
			}
			
			char swap1=uservalues[min].c;         //swapping the entire structure each time with minimum value
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
		print(uservalues,filelength); //printing sorted values
	}
	else if(n==8) //exit if n =8
	{
		delete [] uservalues;
		cout<<"Exiting Current Mode"<<endl<<endl;
		return; //returning to main function
	}
	delete [] uservalues; //deleting the dynamic array as soon as its function is over to prevent memory leaks
}



//function to sort values accoring to amount
//input- an array of structure sortuser and length of the array
//output- sorted array according to amount spent
//we are using selection sort as it is more efficient than bubble sort 

void sortamount(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++) //for loop of minimum values
	{
		int min=i;
		for(j=i+1;j<length;j++)
		{
			if(uservalues[j].amountspent<uservalues[min].amountspent) //for comparing amount spent
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;          //swapping entire structure each time to sort data
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

//function to sort values accoring to number of shares
//input- an array of structure sortuser and length of the array
//output- sorted array according to number of shares
//we are using selection sort as it is more efficient than bubble sort 

void sortnumberofshares(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++) //for loop of minimum values
	{
		int min=i;
		for(j=i+1;j<length;j++)  //for finding miminum values in the array each time
		{
			if(uservalues[j].numberofshares<uservalues[min].numberofshares)  //for comparing according to number of shares
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;  //swapping entire structure each time to sort data
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


//function to sort values accoring to share price
//input- an array of structure sortuser and length of the array
//output- sorted array according to shareprice
//we are using selection sort as it is more efficient than bubble sort
			
void sortshareprice(sortuser uservalues[],int length)
{
	int i,j,min;
	for(i=0;i<(length-1);i++) //for initializing mimimum 
	{
		int min=i;
		for(j=i+1;j<length;j++) //for finding mimumum value in each loop
		{
			if(uservalues[j].shareprice<uservalues[min].shareprice) //for comapring according to share price
			{
				min=j;
			}
		}
		char swap1=uservalues[min].c;   //swapping the entire structure each time
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


//function to print the array of structures with output formatting in columns
//input- an array of structure sortuser and length of the array
//output- prints the array in order

void print(sortuser uservalues[],int filelength)
{
	cout<<endl<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
	for(int j=0;j<filelength;j++)
	{
		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(18)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)
		<<uservalues[j].companyname<<left<<setw(17)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
	}
}


//function to print the array of structures with output formatting in columns
//input- an array of structure sortuser and length of the array
//output- prints the array in  reverse order

void print_reverse(sortuser uservalues[],int filelength)
{
	cout<<endl<<"Shares Bought(B)/Sold(S)   "<<"Amount Spent($)   "<<"Number of shares   "<<"Company Name   "<<"Share Price($)   "<<"Day   "<<endl;
	for(int j=(filelength-1);j>=0;j--)
	{
		cout<<left<<setw(27)<<uservalues[j].c<<left<<setw(18)<<uservalues[j].amountspent<<left<<setw(19)<<uservalues[j].numberofshares<<left<<setw(15)
		<<uservalues[j].companyname<<left<<setw(17)<<uservalues[j].shareprice<<left<<setw(6)<<uservalues[j].day<<endl;
	}
}

