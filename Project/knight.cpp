#include <bits/stdc++.h>
using namespace std;

int step[10][10], q[100][2];
bool use[9][9];

int main() {
    int i, j, k, sr, er;
    char csc, cec;
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    while (cin >> csc >> sr >> cec >> er) {
        int sc = int(csc) - 96;
        int ec = int(cec) - 96;
        int ans = -1, curx, cury, nx, ny;

        memset(step, 0, sizeof(step));
        memset(use, false, sizeof(use));

        step[sr][sc] = 0;
        q[0][0] = sr;
        q[0][1] = sc;
        use[sr][sc] = true;

        for (i = 0, j = 1; i < j; i++) {
            curx = q[i][0];
            cury = q[i][1];

            if (curx == er && cury == ec) {
                ans = step[curx][cury];
                break;
            }

            for (k = 0; k < 8; k++) {
                nx = curx + dx[k];
                ny = cury + dy[k];

                if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
                if (use[nx][ny]) continue;

                use[nx][ny] = true;
                step[nx][ny] = step[curx][cury] + 1;
                q[j][0] = nx;
                q[j][1] = ny;
                j++;
            }
        }

        cout << "To get from " << csc << sr << " to " << cec << er << " takes " << ans << " knight moves." << endl;
    }

    return 0;
}


// e2 e4
// a1 b2
// b2 c3
// a1 h8
// a1 h7
// h8 a1
// b1 c3
// f6 f6




// To get from e2 to e4 takes 2 knight moves.
// To get from a1 to b2 takes 4 knight moves.
// To get from b2 to c3 takes 2 knight moves.
// To get from a1 to h8 takes 6 knight moves.
// To get from a1 to h7 takes 5 knight moves.
// To get from h8 to a1 takes 6 knight moves.
// To get from b1 to c3 takes 1 knight moves.
// To get from f6 to f6 takes 0 knight moves.
