/*
Blood Bottle
Problem
Submissions
Leaderboard
Discussions
Problem Statement

Once two draculas named Zaza and Kaza went to a hospital to drink blood. There were some bottles of blood arranged in a shelf like a binary string (a binary string is a string such that each character in it is either 0 or 1). If the character is 1, that means there is blood in that bottle else not. Zaza will first start drinking, then Kaza and then again Zaza, and so on.

During eating, at a time they can choose any number of consecutive bottles with the same type, after drinking it will be removed from the list.

For example: If the binary string is 0110111, then the optimal way will be,

Zaza will drink- 0110 111 and the string becomes 0110
Kaza will drink- 0 11 0 and the string becomes 00
After that, there is no bottle with blood to drink and they left the hospital. So, Zaza drank 3 bottles, and Kaza drank 2 bottles. Each of them wants to drink more bottles of blood. Can you calculate how many bottles of blood did Zaza drank?

Input Format

First line will contain an integer T, the number of test cases.
Each test case will contain a binary string S.
Constraints

T (1 <= T <= 1000)
S (1 <= |S| <= 100000), here |S| means the length of S.
Output Format

For each test case, output a single line - number of bottles of milk Zaza drank.

Sample Input 0

5
0110111
0101010101
1010101000
0000
111111

Sample Output 0

3
3
2
0
6

*/

/*
5
0110111 ( answer would be 3 as maximum consecutive last 3 111) 
0101010101 ( answer would be 3 zaza take 3 three and kaza 2 ) 
1010101000  (answer would be 2 zaza take 2 three and kaza 2 ) 
0000 ( answer would be zero )
111111 ( 6 as zaza take all 6 kaza can't takey anyone )

*/
#include <iostream>
#include <string>

int calculateZazaBottles(const std::string& s) {
    int zazaBottles = 0;
    int i = s.size() - 1;

    // Find the position of the last '1' in the string
    while (i >= 0 && s[i] != '1')
        i--;

    // Calculate the number of '1's Zaza drinks (last consecutive '1's)
    while (i >= 0 && s[i] == '1') {
        zazaBottles++;
        i--;
    }

    return zazaBottles;
}

int main() {
    int T;
    std::cin >> T; // Read the number of test cases

    for (int t = 0; t < T; ++t) {
        std::string s;
        std::cin >> s; // Read the binary string
        int zazaBottles = calculateZazaBottles(s);
        std::cout << zazaBottles << "\n";
    }

    return 0;
}
