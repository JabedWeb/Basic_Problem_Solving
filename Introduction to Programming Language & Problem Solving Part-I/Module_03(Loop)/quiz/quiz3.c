#include <stdio.h>
int main()
{
    int a = 0, i;
    for (i = 0;i < 5; i++)
    {
        a++;
        continue;
    }
    printf("%d %d",i,a);
    return 0;
}

//a =5;
//i=5;