/*
Problem Statement

Tiger and Pathan are bored with movies and want to play a game. They will play the game in N round. Each time, both of them will guess a number X1 and X2, and whoever guesses the larger number will win that round. The final winner will be the one who wins the most rounds. In the event that they both win an equal number of times, the game will end in a draw.


*/


/*
Sample Input 0
5
10 20
30 20
15 16
100 20
50 45


Sample Output 0
Tiger


*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    int count[2]={0}; // Initialize count array to store number of wins for each player
    printf("Please enter the number\n");
    scanf("%d",&n); 

    for(int i=1;i<=n;i++){
        int x1;         // Tiger
        int x2;         // Pathan

        scanf("%d %d" ,&x1,&x2);

        if(x1>x2){ // If the Tiger player scored more
            count[0]++; // Increment the win count for the Tiger player
        }
        else if (x1==x2){ // If both players scored the same, skip this game
            continue;
        }
        else { // Otherwise, the Pathan player scored more
             count[1]++; // Increment the win count for the Pathan player
        }
    }

    if(count[0]>count[1]){ // If the Tiger player won more games
        printf("Tiger"); // Print out the name of Tiger
    }
    else if (count[0]==count[1]){ // If both players won the same number of games
         printf("Draw"); // Print out that the result is a draw
    }
    else { // Otherwise, the second Pathan won more games
        printf("Pathan"); // Print out the name of the Pathan
    }

    return 0;
}
