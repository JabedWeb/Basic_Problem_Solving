#include <bits/stdc++.h>
using namespace std;

int moveCount[10][10], queuePos[100][2];
bool visited[9][9];

void bfs(int startRow, int startCol, int endRow, int endCol) {
    int i, j, k;
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    int minMoves = -1, currentRow, currentCol, nextRow, nextCol;

    memset(moveCount, 0, sizeof(moveCount));
    memset(visited, false, sizeof(visited));

    moveCount[startRow][startCol] = 0;
    queuePos[0][0] = startRow;
    queuePos[0][1] = startCol;
    visited[startRow][startCol] = true;

    for (i = 0, j = 1; i < j; i++) {
        currentRow = queuePos[i][0];
        currentCol = queuePos[i][1];

        if (currentRow == endRow && currentCol == endCol) {
            minMoves = moveCount[currentRow][currentCol];
            break;
        }

        for (k = 0; k < 8; k++) {
            nextRow = currentRow + dx[k];
            nextCol = currentCol + dy[k];

            if (nextRow < 1 || nextRow > 8 || nextCol < 1 || nextCol > 8) continue;
            if (visited[nextRow][nextCol]) continue;

            visited[nextRow][nextCol] = true;
            moveCount[nextRow][nextCol] = moveCount[currentRow][currentCol] + 1;
            queuePos[j][0] = nextRow;
            queuePos[j][1] = nextCol;
            j++;
        }
    }

    cout << "To get from " << char(startCol + 96) << startRow << " to " << char(endCol + 96) << endRow << " takes " << minMoves << " knight moves." << endl;
}

int main() {
    int startRow, endRow;
    char startColChar, endColChar;

    while (cin >> startColChar >> startRow >> endColChar >> endRow) {
        int startCol = int(startColChar) - 96;
        int endCol = int(endColChar) - 96;
        bfs(startRow, startCol, endRow, endCol);
    }

    return 0;
}
