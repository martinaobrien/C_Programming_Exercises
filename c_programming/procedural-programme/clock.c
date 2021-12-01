#include <stdio.h> //differences between OOP and PP
#include <windows.h> //way of thinking about the programme - there is the data and the methods are sepereate

struct Clock { //data types
    int hours;
    int mins;
    int secs;
};

void tick(struct Clock *c) //same as in python algorithm

{ //same a python
    c-> secs += 1;

    if (c->secs > 59)
    {
        c->mins += 1;
        c->secs += 0;
    }
    if (c->mins > 59)
    {
        c->hours += 1;
        c->mins += 0;
    }
    if (c->hours > 12)
    {
        c->hours += 1;
        c->mins += 0;
        c->mins += 0;
    }
}

void printClock(struct Clock c) //exists outside the data method and the struct has to be passed into it
{
    printf("\n Clock");
    printf("\n%02d:%02d:%02d", c.hours, c.mins, c.secs);
}

void validate(struct Clock *c) //passed in as a point as I don't need to change anything to print it out // this is a built in feature of more modern languages but you have to explicity do it older languages like c
{
    if (c->hours > 12 || c->mins > 60 || c->secs >60)
    {
        c-> hours = 0;
        c-> mins = 0;
        c-> secs = 0;
    }
}

int main ()
{
    struct Clock c = {10,12,24}; //may need to change the data that is stored inside the struct and for that to happen I need to pass it in as a pointer so I can manipulate what is stored inside it
    validate(&c); //this idea is called pass by reference

    while (1)
    {
        tick(&c); //passed by reference with &
        printClock(c);
        Sleep(1000); //milliseconds
    }
    return 0;
} //it is importnat to know who is responsible to what
//from a user perspective it is the same
// evolution of programming languages c doesn't do a great job of extracting the low level details of the operating system you are running on, directly trying to use a library that comes from windows
// more high level programe languages do a much better job of extracting the underlying system that you are using