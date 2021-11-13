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
    cash: float = 0.0
    stock: List[ProductStock] = field(default_factory=list)

@dataclass # dataclasses new on Python 3.7 - you will have to update to get them
class Customer:
    name:str
    budget:float
    shopping_list: List[ProductStock]

def create_and_stock_shop():
    s = Shop () #(200.0, [])
    with open('../stock.csv') as csv_file: #../stock.csv - the .. means go up one level to retrieve the file so all programmes can access it
        csv_reader = csv.reader(csv_file,delimiter=',')
        first row = next(csv_reader)
        print(first row)
        line_count = 0
        for row in csv_reader:
            p = Product(row[0], float(row[1]))
            ps = ProductStock(p,float(row[2]))
            s.stock.append(ps)
            #print(ps)
    return s

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
s = create_and_stock_shop()
print_shop(s) # all lot of similiarities and a lot of difference
#indentation and {}
#dyanmic python and c is static
#data classes and methods are the same