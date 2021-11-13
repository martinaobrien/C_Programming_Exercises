#written in procedural style - Python supports various programs
from dataclasses import dataclass # closest to the struct
from typing import List
import csv

@dataclass
class Product:#direction for the programmer doesn't give me type safety, types of variables canchange over time whereas C is static once a double, always a double
    name: str
    price: float

@dataclass
class ProductStock: #all treated like static container
    product: Product
    quantity: int

@dataclass
class Shop: 
    cash: float # = 0.0 - this doesn't work
    stock: List[ProductStock] # = field(default_factory=List) # this doesn't work as field is not defined #means that when a new shop gets created, python uses a factory to generate a new lists
     # dataclasses new on Python 3.7 - you will have to update to get them

@dataclass  
class Customer:
    name:str #= ""
    budget:float #= 0.0
    shopping_list: List[ProductStock] # = # field(default_factory=List) # this can lean in to procedural programming

def create_and_stock_shop():#treat the first line of the csv different from the rest
    s = Shop (200.0, []) #() (200.0, []) This doesn't work
    with open('../stock.csv') as csv_file: #../stock.csv - the .. means go up one level to retrieve the file so all programmes can access it
        csv_reader = csv.reader(csv_file,delimiter=',')
        #first_row = next(csv_reader)
        #print (first_row)
        #s.cash = float (first_row[0])
        line_count = 0
        for row in csv_reader:
            p = Product(row[0], float(row[1]))
            ps = ProductStock(p,float(row[2]))
            s.stock.append(ps)
            #print(ps)
    return s

def read_customer (file_path):
    with open(file_path) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        first_row = next(csv_reader)
        c = Customer(first_row[0],float(first_row[1]))
        print(c)


def print_product(p):
    print(f'\nPRODUCT NAME: {p.name} \nPRODUCT PRICE: {p.price}')#f embeds a variable in a string(python 3.6 - put your variable in {})

def print_customer(c): #print statement is outside of the class in line with procedural programming
    print(f'CUSTOMER NAME: {c.name} \nCUSTOMER BUDGET: {c.budget}')

    for item in c.shopping_list:
        print_product(item.product)

        print(f'{c.name} ORDERS {item.quantity} OF ABOVE PRODUCT')
        cost = item.quantity * item.product.priceprint(f'The cost to {c.name} will be €{cost}')

def print_shop(s):
    print(f' Shop has {s.cash} in cash')
    for item in s.stock:
        print_product(item.product)
        print(f'The Shop has {item.quantity} of the above')

#p = Product("Coke", 1.0)
#s = create_and_stock_shop()

    c = read_customer('../customer.csv')
# print_shop(s) # all lot of similiarities and a lot of difference
#indentation and {}
#dyanmic python and c is static
#data classes and methods are the same