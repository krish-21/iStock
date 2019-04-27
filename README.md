# 2018/19 Semester 2 ENGG1340 Course Project (Group 21)

#### Group members

- Krishna Nanduri (3035551278)
- Harsh Agarwal   (3035553549)


## Introduction

### Problem Statement


Finance is the most important economic sector in Hong Kong. Understanding finance in quintessential to for evryone in  Hong Kong.


Finance is broadly divided into three primary areas :

1. Corporate Finance
2. Investments
3. Financial Markets & Institutions


There are four different types of Investments each with distinct characteristics, risks and benefits :

1. Stocks
2. Property
3. Cash
4. Fixed Interest


Stocks and Stock Markets : (Wikipedia)

- The stock of a corporation is all of the shares into which ownership of the corporation is divided.

- A stock market, equity market or share market is the aggregation of buyers and sellers (a loose network of economic transactions, not a physical facility or discrete entity) of stocks (also called shares), which represent ownership claims on businesses.


Investors around the world study the stock market for several years, and still, none of them has quite mastered it completely.

Anton Chekhov, one of the greatest writers of short fiction in history, has rightly said **"Knowlege is of no value unless you put it into practice."**


This lack of mastery even after several years of practice could be quite a scary situation for investors who are new to the market. How do investors practice stock trading without actually putting in some money?

This problem is solved by our program **iStock**, a stock market simulator written in C++.

**iStock** lets a User trade stocks of 5 tech giants: Alphabet, Apple, Microsoft, Facebook & Amazon.


### Problem Setting


Problems faced by Investors :

1. No comprehensive portfolio available detailing the stocks owned, credit balance and other relevant information.
2. They do not have an option to set a credit limit for themselves to avoid overspending.
3. No efficient method to look up specific transactions.
4. No efficient way to look at the transaction history in a sorted manner.
5. NO efficient way to look at the stock price history in an integrated environment.


## Features of iStock

### Setting the Credit Limit 

- The credit limit is for the financial security of the User and cannot be changed once set. The credit balance refreshes once every five days.

- Thus the User will have to wait for the cycle to run its course if the credit limit reached.


### Adding Money to the Wallet 

- iStock has an in-app wallet through which all transactions must be made.

- The User can add money at any point in the program, but iStock will always check the credit limit

- The added money will get updated to the Wallet Balance.


### Stock Trading Mode

**Buying Mode :**

- iStock will first show the current market value of the stocks.

- The current portfolio of the User will also be printed.

- iStock will also show the User the Wallet Balance so that the User can make an informed purchase of stocks. Then, the User can buy stocks of the five tech giants.

**Selling Mode :**

- iStock will first show the current market value of the stocks.

- The current portfolio of the User will also be printed.

- iStock will also show the User the Wallet Balance so that the User can make an informed sale of stocks. Then, the User can sell the stocks the User owns.

### Searching Mode 

The User can search transactions from the stored file, records.txt, and choose from six different methods of searching :

1. Amount Spent
2. No. of shares
3. Company Name
4. Shares Bought
5. Shares Sold
6. Day of transaction

### Sorting Mode

The User can sort and print all the transactions made in a specific order and can do so in the following ways :

1. Amount Spent - Ascending order 
2. Amount Spent - Descending order 
3. Number of shares - Ascending order
4. Number of shares - Descending order
5. Share Price - Ascending order
6. Share Price - Descending order
7. Company Name in alphabetical order

### Stock History Mode

- The User can choose a specific company and look at the history of the stocks of the company.

- The User can choose how many days back to look up the stock history.

### Proceeding to the Next Day

The User chooses not to take any action and iStock proceeds to the next day. Consequently, the stock price of each company changes too.

### Exiting iStock

The User chooses to exit iStock. 
The program comes to an end.


## Using iStock



### Implementation of iStock


**DISCLAIMAER : *For the best experience of iStock, please set the Terminal to fullscreen mode*** 

The stock trading starts on Day 1. 

The User should first set your credit limit in the beginning. 

NOTE: The User cannot change the credit limit at any point for financial safety. Thus, the User should be careful when setting the limit. (recommended  to be at least 10000 USD)

The User should enter a positive number. If the input isn't a positive number, iStock will ask the User for another input.

Then, iStock proceeds to the Dashboard, the place for all the information to be displayed for the User.

The dashboard provides the following information :

- The User's Net Worth - The total money, the User has in the stock market. It is calculated by multiplying the number of stocks the User owns multiplied by the current market of value of the corresponding stock.

- The Stocks owned by the User

- The User's Wallet Balance - The money currently present in the in-program wallet.

- The User's Credit Balance - It is calculated by negating the money added to the wallet from the Credit Balance. The credit Balance is reset to the maximum every five days.

- iStock prints the present day at the top-right corner of the dashboard.

Next, iStock prints dashboard menu.

The User has six options :

1. Add money to the Wallet
2. Start Trading Stocks
3. Search for Specific Transactions
4. Sort & View all Transactions
4. Proceed to the next day
5. Exit iStock


After the User finished the day's work, the User can proceed to the next day.

Proceeding to the next day means that the stock of each company changes at the end of each day, thus changing the User's net worth too.

Once agian, iStock prints the dashboard for the User to do the necessary.

Thus, iStock keeps running until the User chooses the fifth option - exit.



### Building and Running iStock


Using iStock is a simple task for anyone with a Unix-based terminal. Follow the trailing instructions, and execute the commands in order. 
However, you are required to have [git](https://www.atlassian.com/git/tutorials/install-git), [g++ compiler](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/), and [make](https://www.gnu.org/software/make/) installed.


1. Clone this GitHub repository :

    `git clone https://github.com/krish-21/iStock.git`

2. Go into iStock's root directory :

    `cd iStock`

3. Build the main program using make : *Our Makefile compiles main.cpp by default*

    `make`

4. Run iStock :

    `./main`


## Limitations and Assumptions

### Limitations

One of the limitations of iStock is that we assume that the User gives the right type of input. Eg. When iStock asks for an integer, it is assumed that the input provided is an integer. 
If a character is given as the input, the program fails to check it and unintended results are observed.

### Assumptions


1. We are assuming that the user will enter an integer where an integer value is needed and a character where a character value is needed.

2. We are assuming that the credit limit entered by the user will not be over the range of double in C++

3. We are assuming that when the program starts, after entering the name, the bank account of the user will automatically get linked to our program as we dont have the data of user's bank account and therefore, there is no way we can confirm and check the password of user's bank account.
   The money is then automatically transferred from user's bank account when he wants to do stock trading.
