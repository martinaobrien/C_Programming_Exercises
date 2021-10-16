#include <stdio.h>
#include <string.h>
//struct is a way of combining pieces of data together
// C is not as advanced so it cannot refer to a struct unless it has processed it - Product Stock must come before customer as customer refers to it

struct Product {
    char* name;
    double price;
};

struct ProductStock{
    struct Product product; // must give it a name of a struct
    int quantity;
}; //ending the definition of a struct is a ; semi colon

struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppingList[10];//the amount has to go in an array after the identifier which is the variable
    int index;
};

struct Shop{
    double cash;
    struct ProductStock stock[20];
};

void printProduct(struct Product p)
{
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
    printf("----------\n");
}

void printCustomer(struct Customer c)
{
    printf("CUSTOMER NAME: %s \nCUSTOMER PRICE: %.2f\n", c.name,c.budget);
    printf("----------\n");
    for(int i = 0; i < c.index; i++)
    {
        printProduct(c.shoppingList[i].product);
        printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
        double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price; 
        printf("The cost to %s will be %.2f euro\n", c.name, cost);
    }
}
int main (void)
{
    struct Customer dominic = { "Dominic", 100.0};
    //printCustomer(dominic);

    struct Product coke = { "Can Coke", 1.10};
    struct Product bread = { "Bread", 0.70};
    // printProduct(coke);

    struct ProductStock cokeStock = { coke, 20 };
    struct ProductStock breadStock = { bread, 2 };

    dominic.shoppingList[dominic.index++] = cokeStock; // retrieve the vaule from index and increment it
    dominic.shoppingList[dominic.index++] = breadStock;

    printCustomer(dominic);
// printf ("The shop has %d 0f the product %s\n", cokeStock.quantity,cokeStock.product.name);

    return 0;
}
//when you right everything in the programme, the compilier knows how much it needs
//there is no memory management in this so far which is neccessary when you take in data from outside, you don't know the amount that will be taken in