#include <stdio.h>
int main () {
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    float di=(float)a/b;
    printf("%d + %d = %d\n",a, b,a+b);
    printf("%d - %d = %d\n",a, b,a-b);
    printf("%d * %d = %d\n",a, b,a*b);
    printf("%d / %d = %.2f\n",a, b,di);
}