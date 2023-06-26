import java.util.Arrays;
import java.util.Scanner;

public class KnightMoves {
    static int[][] moveCount = new int[10][10];
    static int[][] queuePos = new int[100][2];
    static boolean[][] visited = new boolean[9][9];

    public static void bfs(int startRow, int startCol, int endRow, int endCol) {
        //System.out.println("Start: " + startRow + " " + startCol);
        //System.out.println("End: " + endRow + " " + endCol);
        int[] dx = {1, 1, -1, -1, 2, 2, -2, -2};
        int[] dy = {2, -2, 2, -2, 1, -1, 1, -1};

        int minMoves = -1;
        int currentRow, currentCol, nextRow, nextCol;
        int j;

        for (int[] row : moveCount) {
            Arrays.fill(row, 0);
        }
        for (boolean[] row : visited) {
            Arrays.fill(row, false);
        }

        // show 2D array of moveCount
        // for (int[] row : moveCount) {
        //     for (int col : row) {
        //         System.out.print(col + " ");
        //     }
        //     System.out.println();
        // }

        moveCount[startRow][startCol] = 0;
        queuePos[0][0] = startRow;
        queuePos[0][1] = startCol;
        visited[startRow][startCol] = true;

        for (int i = 0, k = 1; i < k; i++) {

            currentRow = queuePos[i][0];
            currentCol = queuePos[i][1];
            //System.out.println("Current 35: " + currentRow + " " + currentCol);

            if (currentRow == endRow && currentCol == endCol) {
                      //System.out.println("Current 38: " + currentRow + " " + currentCol);
                minMoves = moveCount[currentRow][currentCol];
               // System.out.println("Min: " + minMoves);
                break;
            }

            for (j = 0; j < 8; j++) {
                nextRow = currentRow + dx[j];
                nextCol = currentCol + dy[j];
                //System.out.println("Next 48: " + nextRow + " " + nextCol);

                if (nextRow < 1 || nextRow > 8 || nextCol < 1 || nextCol > 8) {
                    continue;
                }
                if (visited[nextRow][nextCol]) {
                    continue;
                }

                visited[nextRow][nextCol] = true;
                moveCount[nextRow][nextCol] = moveCount[currentRow][currentCol] + 1;
               // System.out.println("Move count 58: " + moveCount[nextRow][nextCol]);
                //         // show 2D array of moveCount
                // for (int[] row : moveCount) {
                //     for (int col : row) {
                //         System.out.print(col + " ");
                //     }
                //     System.out.println();
                // }
                queuePos[k][0] = nextRow;
                queuePos[k][1] = nextCol;
                k++;
            }
        }

        System.out.println("To get from " + toAlgebraicNotation(startCol, startRow) + " to " + toAlgebraicNotation(endCol, endRow) + " takes " + minMoves + " knight moves.");
    }

    public static String toAlgebraicNotation(int col, int row) {
        char colChar = (char) (col + 'a' - 1);
        return colChar + "" + row;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String input = scanner.nextLine();
            int startCol = input.charAt(0) - 'a' + 1;
            int startRow = input.charAt(1) - '0';
            int endCol = input.charAt(3) - 'a' + 1;
            int endRow = input.charAt(4) - '0';

            bfs(startRow, startCol, endRow, endCol);
        }
    }
}
