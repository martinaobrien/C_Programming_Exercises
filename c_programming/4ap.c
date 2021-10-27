#include <stdio.h>
void print(int times, char a)
{
    for(int i = 0; i < times; i++)
    {
        printf("%c", a);
    }
    printf("\n");    
}

int main()
{
    print(6, '#');
    print(2, '#');
}