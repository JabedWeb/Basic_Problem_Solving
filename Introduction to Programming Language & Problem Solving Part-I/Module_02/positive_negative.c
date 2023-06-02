#include <stdio.h>

int main() {
   int n;
   int result;

   printf("Enter a value: ");
   result = scanf("%d", &n);

   if (result == 1) {
      if (n == 0) {
         printf("Zero");
      } else if (n > 0) {
         printf("Positive");
      } else {
         printf("Negative");
      }
   } else {
      printf("Invalid input");
   }

   return 0;
}