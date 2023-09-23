#include <bits/stdc++.h>
using namespace std;

typedef pair <long long,int> pii;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pii> heightIndex(n);
        for (int i = 0; i < n; i++) {
            cin >> heightIndex[i].first;
            heightIndex[i].second = i;
        }

       
        sort(heightIndex.begin(), heightIndex.end(), greater<pair<int, int>>());

        cout << min(heightIndex[0].second, heightIndex[1].second)  << " "
             << max(heightIndex[0].second, heightIndex[1].second) << endl;
    }

    return 0;
}
