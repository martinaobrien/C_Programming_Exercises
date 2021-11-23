#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int index;
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

struct Shop createAndStockShop() //need to read in a file
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen("stock-_c.csv","r"); //r = read rw = read write is what we are opening the file for
    if (fp == NULL)
        exit(EXIT_FAILURE); // error handling

    read = getline(&line, &len, fp);
    float cash = atof(line);
    // printf ("cash in shop is %.2f\n", cash);
    struct Shop shop = {cash};
    
    while ((read = getline(&line, &len, fp)) != -1) { //this line gets called every iteratin of the loop
        //printf ("Retrieved line of length %zu:\n", read);
        //printf("%s IS A LINE", line);
        char *n = strtok(line, ",");
        char *p = strtok(NULL, ","); //special term - no information is being passed
        char *q = strtok(NULL, ",");
        int quantity = atoi(q);
        double price = atof(p);
        char *name = malloc(sizeof(char) * 50);//manually allocate a piece of memory on the computer for us to store information
        strcpy(name, n);
        struct Product product = { name, price};
        struct ProductStock stockItem = { product, quantity};
        shop.stock[shop.index++] = stockItem; //adding in stock - at the end of this method, the shop should have all the items from the csv stored in it
        //printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
        }

        return shop; 
}

void printShop (struct Shop s)
{
    printf("Shop has %.2f in cash\n", s.cash);
    for (int i = 0; i <s.index; i++) //first part is the initialiser, second part the condition, final part the incrementer
    {
        printProduct(s.stock[i].product);
        printf("The shop has %d of the above\n", s.stock[i].quantity);
    }
}
int main (void)
{
    //struct Customer dominic = { "Dominic", 100.0};
    //printCustomer(dominic);

    //struct Product coke = { "Can Coke", 1.10};
    //struct Product bread = { "Bread", 0.70};
    // printProduct(coke);

    //struct ProductStock cokeStock = { coke, 20 };
    //struct ProductStock breadStock = { bread, 2 };

    //dominic.shoppingList[dominic.index++] = cokeStock; // retrieve the vaule from index and increment it
    //dominic.shoppingList[dominic.index++] = breadStock;

    //printCustomer(dominic);
// printf ("The shop has %d 0f the product %s\n", cokeStock.quantity,cokeStock.product.name);

//create a method to read in the stock
    struct Shop shop = createAndStockShop();
    printShop(shop);
    return 0;
}
//when you right everything in the programme, the compilier knows how much it needs
//there is no memory management in this so far which is neccessary when you take in data from outside, you don't know the amount that will be taken in