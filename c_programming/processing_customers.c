#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
 
struct Customer {
    char* name;
	double budget;
};
 
struct Customer custOrder()
{
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("customer.csv", "r"); //only handling the first line of the customer csv
    if (fp == NULL)
        exit(EXIT_FAILURE);
	
	read = getline(&line, &len, fp); // pull into the line variable
    char *a = strtok(line, ","); //name
    char *b = strtok(NULL, ","); // budget/
    char *custName = malloc(sizeof(char) * 50); //memory to store that
    double custBudget = atof(b); //get the customer budget by gettting the floating point number
    strcpy(custName, a); //copy from the charater a to our newly appointed memory
	struct Customer customer = { custName, custBudget}; //create the customer here
	
    while ((read = getline(&line, &len, fp)) != -1) { // modify from shop stock - strtk. atof not atoi . atof uses a floating point number
    // product stock etc from previous videos and look at other processing the shop video/code
		// TODO process remaining lines
	}        
	return customer;
}   

int main(void) 
{
    struct Customer customer = custOrder();
	printf("Customer name is: %s and they have: %.2f for their budget\n", customer.name, customer.budget);
    return 0;
}