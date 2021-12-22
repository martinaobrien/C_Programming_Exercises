## Multi-Paradigm Programming Project 2021

This folder contains the all files needed for the Multi Paradigm Programming Shop Assignment submitted as part of the Higher Diploma in Data Analytics in GMIT 2021/2021. 
These are:

Shop Code:
	Procedural in C
	Procedural in Python
	Object Orientated in Python

CSV files:	Greedy Gemma
	No Money Mark
	All okay
	Stock

Project Report 

Purpose of the Assignment: 

The assignment was to build a Shop program with the below functionality as outlined below and compare the implementations of each shop instance. This document serves to provide the user with an overview of the project and how to run the code on their own machne. 

Functionality of the Shop as per project assignment:

The shop CSV should hold the initial cash value for the shop.
Read in customer orders from a CSV file.
	That file should include all the products they wish to buy and in what quantity.
	It should also include their name and their budget.
The shop must be able to process the orders of the customer.
	Update the cash in the shop based on money received.
		It is important that the state of the shop be consistent.
		You should create customer test files (CSVs) which can and cannot be completed by the shop.
	Know whether or not the shop can fill an order
		Throw an appropriate error
Operate in a live mode, where the user can enter a product by name, specify a quantity, and pay for it. The user should be able to buy many products in this way.

Notes:

	The above described functionality to be completed in both Python and C in a procedural programming style.
	The functionality of the shop is replicated in Python in an Object Oriented style.
	The live mode, and the input files, should have the exact same behaviour in all implementations i.e "user experience" should be with an identical

Report
The report included in the project should compare the solutions acheived using the procedural and object orientated approaches.

Running the Shop:

Procedural Code
C Shop
	Once in the c folder, run gcc.shop.c from your computers command line to compile the program into a file called a.out. Once compiled the program can be run using  ./a.out  

Python Shop
	Once in the python folder, execute the command python shop.py from your command line

Object Oriented Style
	Once in the python_oop folder, execute the command python shop_oop.py to run the program from the command line.


The Shop's User Interface:
	Once each program is running, the user experience is the same for each style as outlined:
		The user interacts with a display menu with several options: 
			Option 1:
			Option 2:
			Option 3:
			Option 4:
			Option 5:
	


Option 1 is to print the current shop state. This will show the cash and stock amounts in the shop whenever it is called. Initially the shop cash and stock items are read from a csv file called stock.csv. Once read in the file is no longer used.
Option 2 gives the user the option to act as a customer that has an order in a file. The user is asked to enter the name of the file. The user should just enter the name of the file without the .csv extension. For example a file named customer.csv is just entered as customer and likewise with all the other customer files.
Option 3 gives the user the option to enter a live mode, where the user can enter a product by name, specify a quantity, and pay for it. The user can buy many products in this way.
Test files
There are several test files in the main folder.

customer.csv, customer1.csv and customer2.csv are customer file containing orders that the shop can fill from the stock at the start of the program execution. The shop stock and cash is updated after every successful order has been processed whether this is a live or batch order. Therefore it is possible that one of these orders cannot be completly filled if the shop stock has already been sold.
There are also some test files as required that the shop cannot completely fulfill.

fred.csv contains an item that the shop does not stock at all.
joe.csv contains several products that the shop does not stock at all.
mike.csv contains two products, including one item that the shop does not stock.
bad.csv and broke.csv are customer files where the customer does not have enough cash to pay for their shopping order.
poor.csv is a customer file where the customer does not have enough cash to purchase all the items on their shopping order.
coke.csv is a customer file where the customer is looking for a higher quantity of a product than the shop has in stock.
