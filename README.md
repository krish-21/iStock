# 2018/19 Semester 2 ENGG1340 Course Project (Group 21)

#### Group members
- Krishna Nanduri (3035551278)
- Harsh Agarwal (3035553549)


## Introduction


### Problem Statement

Finance is the most important economic sector in Hong Kong. Understanding finance in quintessential to all Hong Kongers.

Finance is broadly divided into 3 primary areas :

1. Corporate Finance
2. Investments
3. Financial Markets & Institutions


There are 4 different types of Investments each with distinct characteristics, risks and benefits :

1. Stocks
2. Property
3. Cash
4. Fixed Interest


Stocks and Stock Markets : (Wikipedia)

- The stock of a corporation is all of the shares into which ownership of the corporation is divided.

- A stock market, equity market or share market is the aggregation of buyers and sellers (a loose network of economic transactions, not a physical facility or discrete entity) of stocks (also called shares), which represent ownership claims on businesses.


Investors around the world study the stock market for several years, and still, none of them has quite mastered it completely.

Anton Chekhov, one of the greatest writers of short fiction in history, has rightly said **"Knowlege is of no value unless you put it into practice"**


This lack of mastery even after several years of practice could be quite a scary situation for investors who are new to the market.

How do investors practice stock trading without actually putting in some money?

This problem is solved by our program **iStock**, a stock market simulator written in C++.

**iStock** lets you trade stocks of 5 tech giants: Alphabet, Apple, Microsoft, Facebook & Amazon.


### Problem Setting

Problems faced by Investors :

1. No comprehensive portfolio available detailing the stocks owned, credit balance and other relevant information.
2. They do not have an option to set a credit limit for themselves to avoid overspending.
3. No efficient method to look up specific transactions.
4. No efficient way to look at the transaction history in a sorted manner.


##Features of iStock

...........Have to write features..............


## Using iStock


### Implementation of iStock

The stock trading starts on Day 1. 

The User should first set your credit limit in the beginning. 

NOTE: The User cannot change the credit limit at any point for financial safety. Thus, the User should be careful when setting the limit. (recommended  to be at least 10000 USD)

The User should enter a positive number. If the input isn't a positive number, iStock will ask the user for another input.

Then, iStock proceeds to the Dashboard, the place for all the information to be displayed for the user.

The dashboard provides the following information :

- The User's Net Worth - The total money, the user has in the stock market. It is calculated by multiplying the number of stocks the user owns multiplied by the current market of value of the corresponding stock.

- The Stocks owned by the user

- The User's Wallet Balance - The money currently present in the in-program wallet.

- The User's Credit Balance - It is calculated by negating the money added to the wallet from the Credit Balance. The credit Balance is reset to the maximum every five days.

- iStock prints the present day at the top-right corner of the dashboard.

Next, iStock prints dashboard menu.

The user has six options ;

1. Add money to the Wallet
2. Start Trading Stocks
3. Search for Specific Transactions
4. Sort & View all Transactions
4. Proceed to the next day
5. Exit iStock


After the user finished the day's work, the user can proceed to the next day.

Proceeding to the next day means that the stock of each company changes at the end of each day, thus changing the user's net worth too.

iStock again prints the dashboard for the user to do the necessary.

iStock keeps running until the user chooses the fifth option to exit.



### Building and Running iStock

Using iStock is a simple task for anyone with a Unix-based terminal. Follow the trailing instructions, and execute the commands in order. 
However, you are required to have [git](https://www.atlassian.com/git/tutorials/install-git), [g++ compiler](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/), and [make](https://www.gnu.org/software/make/) installed.


1.Clone this GitHub repo.

`git clone https://github.com/krish-21/iStock.git`

2.Go into the project root directory.

`cd iStock`

3.Build the main program using make. *Our makefile defaults to compiling main.cpp.*

`make`

4.Start running iStock.

`./main`


##Limitations and Improvements

One of the limitations of iStock is that we assume that the user gives the right type of input. Eg. When iStock asks for an integer, it is assumed that the input provided is an integer. 
If a character is given as the input, the program fails to check it and unintended results are observed.
