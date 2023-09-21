#include <bits/stdc++.h>
using namespace std;

bool can_become_abc(string cards) {
    if (cards == "abc") {
        return true;
    }
    return (cards[0] == 'a' && cards[1] == 'c' && cards[2] == 'b') ||
           (cards[0] == 'b' && cards[1] == 'a' && cards[2] == 'c') ||
           (cards[0] == 'c' && cards[1] == 'b' && cards[2] == 'a');
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string cards;
        cin >> cards;

        if (can_become_abc(cards)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}