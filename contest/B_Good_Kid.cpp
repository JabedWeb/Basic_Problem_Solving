#include <bits/stdc++.h>
using namespace std;

int maxProduct(int n, vector<int>& digits) {
    sort(digits.begin(), digits.end()); 
    digits.front() += 1; 

    int maxProduct = 1;
    for (int i = 0; i < n; ++i) {
        maxProduct *= digits[i];
    }

    return maxProduct;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> digits(n);
        for (int i = 0; i < n; ++i) {
            cin >> digits[i];
        }

        int result = maxProduct(n, digits);
        cout << result << endl;
    }

    return 0;
}
