#include<stdio.h>
int main(void)
{
    printf("%d",test(53));
    printf("\n%d",test(30));
    printf("\n%d",test(51));
}
int test(int n)
    {
        const int x=51;

        if(n>x)
        {
            return(n-x)*3;
        }
        return x-n;

    }

 if(default_value>=number){
    printf("%d",abs(default_value-number));
 }
 else if(default_value<=number){
    printf("%d",(abs(default_value-number))*3);
 }

}