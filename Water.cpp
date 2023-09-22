#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void water(vector<long long> heights) {
    int n = heights.size();
    long long max1 = -1, max2 = -1;
    int maxIndex1 = -1, maxIndex2 = -1;

    for (int i = 0; i < n; i++) {
        if (heights[i] > max1) {
            max2 = max1;
            maxIndex2 = maxIndex1;
            max1 = heights[i];
            maxIndex1 = i;
        } else if (heights[i] > max2) {
            max2 = heights[i];
            maxIndex2 = i;
        }
    }

    cout << min(maxIndex1, maxIndex2)<< " " << max(maxIndex1, maxIndex2) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        water(heights);
    }

    return 0;
}
