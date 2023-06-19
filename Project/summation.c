#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    long long int i,sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    printf("%lld\n",llabs(sum));
    return 0;
}