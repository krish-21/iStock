#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

#include "start.h"

using namespace std;

struct users
{
	string name;
	string userid;
	string password;
};

bool newuser(int n)
{
	
	label1:
	
	if(n==1)
	{
		users newuser;
		cout<<"Enter Your Name"<<endl;
		cin>>newuser.name;
		cout<<"Enter User ID"<<endl;
		cin>>newuser.userid;
		cout<<"Enter Password"<<endl;
		cin>>newuser.password;
		ofstream foutusers;
		foutusers.open("users.txt",ios::app);
		if(foutusers.fail())
		{
			cout<<"Unable to open text file"<<endl;
			exit(1);
		}
		foutusers<<newuser.name<<" "<<newuser.userid<<" "<<newuser.password<<endl;
		foutusers.close();
		return true;
	}
	
	else if(n==2)
	{
		string uid,password;
		cout<<"Enter User Id"<<endl;
		cin>>uid;
		ifstream finusers;
		finusers.open("users.txt",ios::app);
		if(finusers.fail())
		{
			cout<<"Unable to find you"<<endl;
			exit(1);
		}
		int n=10;
		users a[10];
		string line;
		int initialize=0;
		while(finusers>>a[initialize].name>>a[initialize].userid>>a[initialize].password)
		{
			initialize++;
		}
		int i,pos=-1;
		while(pos<0)
		{
			for(i=0;i<n;i++)
			{
				if(a[i].userid==uid)
				{
					cout<<"Uid found"<<endl;
					pos=i;
					break;
				}
			}
			if(pos<0)
			{
				cout<<"UID not found"<<endl;
				cout<<"Enter UID again"<<endl;
				cin>>uid;
			}	
		}
		cout<<"Enter Password"<<endl;
		while(true)
		{
			cin>>password;
			if(a[i].password==password)
			{
				cout<<"Login Successful"<<endl;
				return true;
			}
			else
			{
				cout<<"Incorrect Password"<<endl;
				cout<<"Enter Password Again"<<endl;
			}
		}
	}

	else
	{
		cout<<"Invalid input"<<endl<<endl;
		goto label1;
	}
	
}

void display()
{
	cout<<"Welcome to abcd"<<endl;
	cout<<"1- Create New Account"<<endl;
	cout<<"2- Login"<<endl;
	int n;
	cin>>n;
	newuser(n);
}
