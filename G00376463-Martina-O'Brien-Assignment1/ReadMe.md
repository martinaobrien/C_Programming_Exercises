# Multi-Paradigm Programming Project 2021

## About the Project
This project is submitted as part of the requirements for the Higher Diploma in Data Analytics in GMIT for the Winter Semester 2021
#### Module: Multi Paradigm Programme 52960
#### Lecturer: Dominic Carr
#### Student: Martina O'Brien
#### Student No: G00376463
#### Date Submitted: 22nd of December 2022

### Folder Contents

This folder contains the all sub folders needed for the Multi Paradigm Programming Shop Assignment.
These include:

#### 1. ReadMe
This file provides
- an overview of the project and its requirements
- information on how to run the programs in each instance

#### 2. Shop Folders(there is one folder for each instance):
- Shop in Procedural Program in C (shop.c)
- Shop in Procedural Program in Python (shop.py)
- Shop in Object Orientated in Python (shop_oop.py)

#### 3. Data Folder:
- good_customer
- no_funds_customer
- greedy_customer
- shop_stock

#### 4.Project Report 
A pdf file containing comparisons and analysis of the implementation of each of the 3 shops outline above

## Overview of the Project and its Requirements: 

The assignment was to build a Shop program with the below functionality as outlined below and compare the implementations of each shop instance. This document serves to provide the user with an overview of the project and how to run the code on their own macihne. 

### Requirements of the Shop as per project assignment:

Below is a detailed description of the key elements included in the folder as per requirements of assignments
#### Requirements of the assignment:
 - The shop CSV should hold the initial cash value for the shop.
 - Read in customer orders from a CSV file.
	- That file should include all the products they wish to buy and in what quantity.
	- It should also include their name and their budget.
- The shop must be able to process the orders of the customer.
	- Update the cash in the shop based on money received.
		a) It is important that the state of the shop be consistent.
		b) You should create customer test files (CSVs) which can and cannot be completed by the shop.
	- Know whether or not the shop can fill an order
		a) Throw an appropriate error
- Operate in a live mode, where the user can enter a product by name, specify a quantity, and pay for it. The user should be able to buy many products in this way.

#### Notes:
- The above described functionality to be completed in both Python and C in a procedural programming style.
- The functionality of the shop is replicated in Python in an Object Oriented style.
- The live mode, and the input files, should have the exact same behaviour in all implementations i.e "user experience" should be with an identical

## Running the Program:

### Running each of the Shop instances

#### Procedural Code
- C Shop (shop.c)
Once in the c folder, run gcc.shop.c from your computers command line to compile the program into a file called a.out. Once compiled the program can be run using  ./a.out  

- Python Shop (python.py)
Once in the python folder, execute the command python shop.py from your command line

#### Object Oriented Style
- Python Shop (python_oop.py)
Once in the python_oop folder, execute the command python shop_oop.py to run the program from the command line.

#### How to operate the Shop instances

Once the program is executed, the user experience is the same for each style as follows

The user interacts with a display menu with several options: 
- Option 1: Shop Stock
   - Prints ths current shop state including its current stock and cash.This is read from the shop_stock csv file This is constant throughout the experience and reverts back to  its inital stock and cash after the program is exited
- Option 2: Good Customer
   - Reads in the good_customer csv file which is then processed by the shop and the shop cash and stock is updated accordingly
- Option 3: No Funds Customer
   - Reads in the no_funds_customer csv file where the order cannot be processed as the customer does not have the required budget The shop stock and cash is updated accordingly.
- Option 4: Greedy Customer
   - Reads in the greedy_customer csv file where the order takes in an item not stock by the shop and also the shopping list asks for more items than the shop has in stock. The shop stock and cash is updated accordingly.
- Option 5: New Customer - Live Mode
   - This is a live mode where a user enters the shop by inputting their name and then they are asked to input their budget. The user then has the option to input one item they require at a time and the quantity of that item. They have the option to select further items after each item is processed and their budget is updated and shown to the user after each item is purchased The shop stock and cash is updated accordingly. The user can press x to leave this mode.
- Option 6: Exit
   - The option exits the program and the user can see the updated cash of the shop after all of its customers.
	


