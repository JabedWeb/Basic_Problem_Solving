#include <bits/stdc++.h>
using namespace std;

typedef pair <long long,int> pii;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pii> hight_Index(n);
        for (int i = 0; i < n; i++) {
            cin >> hight_Index[i].first;
            hight_Index[i].second = i;
        }

       
        sort(hight_Index.begin(), hight_Index.end(), greater<pair<int, int>>());

        cout << min(hight_Index[0].second, hight_Index[1].second)  << " "
             << max(hight_Index[0].second, hight_Index[1].second) << endl;
    }

    return 0;
}
