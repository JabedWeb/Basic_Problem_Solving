import java.util.Scanner;

public class Dropping {
    static int bound;

// Recursive function to calculate the final position of the ball
public static int getFinalPosition(int currentDepth, int currentBallNumber) {
    if (currentDepth >= bound) {
        return currentDepth;
    }
    int leftChild = currentDepth * 2;
    int rightChild = leftChild + 1;
    if (currentBallNumber % 2 == 0) {
        return getFinalPosition(rightChild, currentBallNumber / 2);
    } else {
        return getFinalPosition(leftChild, (currentBallNumber + 1) / 2);
    }
}

public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the number of test cases: ");
    int numTests = scanner.nextInt();

    while (numTests-- > 0) {
        System.out.print("Enter the depth and ball number: ");
        int depth = scanner.nextInt();
        int ballNumber = scanner.nextInt();
        bound = 1; // Initialize bound to 1

        for (int i = 0; i < depth - 1; i++) {
            bound *= 2; // Calculate the bound based on the given depth
        }

        int finalPosition = getFinalPosition(1, ballNumber); // Start from depth 1
        System.out.println("Final position: " + finalPosition);
    }
}

}
