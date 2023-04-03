#include<stdio.h>
int main() {
    int money_amount;
    scanf("%d",&money_amount);
    if(money_amount>20000){
        printf("Gucci Bag\n");
        printf("Gucci Belt");
    }
    else if (money_amount>1000){
        printf("Gucci Bag");
    }
    else if (money_amount>5000){
        printf("Levis Bag");
    }
    else {
        printf("Something");
    }
}