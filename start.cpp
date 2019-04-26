#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
string newuser(Investor);

struct users
{
	string name;
	string userid;
	string password;
	double creditlimit;
	double wallet_balance;
	double networth;
	double google;
	double apple;
	double microsoft;
	double facebook;
	double amazon;
};

string newuser(Investor &user)
{
	cout<<"Welcome to iStock"<<endl;
	cout<<"1- Create New Account"<<endl;
	cout<<"2- Login"<<endl;
	cout<<"3- Exit"<<endl;
	int n;
	cin>>n;
	while(n<1 || n>3)
	{
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Value again"<<endl;
		cin>>n;
	}
	if(n==1)
	{
		users newuser;
		cout<<"Enter Your Name"<<endl;
		cin>>newuser.name;
		cout<<"Enter User ID"<<endl;
		cin>>newuser.userid;
		cout<<"Enter Password"<<endl;
		cin>>newuser.password;
		cout<<"Enter Your Credit Limit"<<endl;
		cin>>newuser.creditlimit;
		newuser.wallet_balance=0;
		newuser.networth=0;
		newuser.google=0;
		newuser.apple=0;
		newuser.microsoft=0;
		newuser.facebook=0;
		newuser.amazon=0;
		ofstream foutusers;
		foutusers.open("users.txt",ios::app);
		if(foutusers.fail())
		{
			cout<<"Unable to open users.txt"<<endl;
			exit(1);
		}
		foutusers<<newuser.name<<" "<<newuser.userid<<" "<<newuser.password<<" "<<newuser.creditlimit<<" "<<newuser.wallet_balance<<" "<<newuser.networth
		<<" "<<newuser.google<<" "<<newuser.apple<<" "<<newuser.microsoft<<" "<<newuser.facebook<<" "<<newuser.amazon;
		foutusers.close();
		cout<<"Successfully created your account"<<endl;
		set_name(newuser.name);
		set_net_worth();
    	set_wallet_balance(newuser.wallet_balance);
    	set_net_worth(newuser.networth);
   		set_credit_limit(newuser.creditlimit);
		
		return newuser.userid;
	}
	else if(n==2)
	{
		string uid,password;
		cout<<"Enter User Id"<<endl;
		cin>>uid;
		ifstream finusers;
		finusers.open("users.txt");
		if(finusers.fail())
		{
			cout<<"Unable to open users.txt"<<endl;
			exit(1);
		}
		string line;
		int length;
		while(getline(finusers,line))
		{
			length++;
		}
		users * userdetails=new users[length];
		finusers.clear();
		finusers.seekg(0, ios::beg);
		int k=0;
		while(finusers>>userdetails[k].name>>userdetails[k].userid>>userdetails[k].password>>userdetails[k].creditlimit>>userdetails[k].wallet_balance>>
		newuser[k].networth>>userdetails[k].google>>userdetails[k].apple>>userdetails[k].microsoft>>userdetails[k].facebook>>userdetails[k].amazon)
		{
			k++;
		}
		int i,pos=-1;
		while(pos<0)
		{
			for(i=0;i<length;i++)
			{
				if(userdetails[i].userid==uid)
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
		cin>>password;
		while(userdetails[pos]!=password)
		{
			cout<<"Incorrect Password"<<endl;
			cout<<"Enter Password Again"<<endl;
			cin>>password;
		}
		cout<<"Login Successful"<<endl;
		set_name(userdetails[pos].name);
    	set_net_worth(userdetails[pos].networth);
    	set_wallet_balance(userdetails[pos].wallet_balance);
    	set_credit_limit(userdetails[pos].creditlimit);
	}
	else if(n==3)
	{
		cout<<"Thanks for using iStock"<<endl;
		exit(1);
	}
}


