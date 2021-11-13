#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//bunch of conditional statements
void askName(){ //creating its own method
    fflush(stdin); //flushes the input - clear input stream
    printf("What is your name?\n");
    char name[10];
    fgets(name,10,stdin); //NB
    printf("Glad to meet you, %s\n", name);
}
int main(void)
{
    int choice = -1;
    while (choice!= 0){
        fflush(stdin);
        printf("\nPlease choose an option ");
        scanf ("%d" , &choice); //NB

        if(choice == 1)
        {
            printf ("The user pressed 1\n");
        } else if (choice == 2){
            printf ("here we can do something else");
        } else if (choice == 3){
            askName();
            //fflush(stdin); //flushes the input - clear input stream
            //printf("What is your name?\n");
            //char name[10];
            //fgets(name,10,stdin); //NB
            //printf("Glad to meet you, %s\n", name);
        }
        
    }
    printf("Buh bye");
}