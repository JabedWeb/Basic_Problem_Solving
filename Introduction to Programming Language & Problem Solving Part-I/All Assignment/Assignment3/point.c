#include <stdio.h>
    int main()
    {
        int ary[4] = {1, 2, 3, 4};
        int *p;
        printf("%d\n",*ary);
        printf("%d\n",ary);
        p = ary + 3;
        printf("%d\n",p);
        *p = 5;
        printf("%d\n", ary[3]);
    }