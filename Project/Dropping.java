import java.util.Scanner;

public class Dropping {
    static int bound;

// Recursive function to calculate the final position of the ball
public static int getFinalPosition(int currentDepth, int currentBallNumber) {
    //System.out.println("Current depth: " + currentDepth + ", current ball number: " + currentBallNumber);
     //if the current depth is equal to or greater than the bound. If it is, it means the ball has reached the final depth, so the current depth is returned as the final position of the ball.
     if (currentDepth >= bound) {
        return currentDepth;
    }

    int leftChild = currentDepth * 2;
    int rightChild = leftChild + 1;
    System.out.println("Left child: " + leftChild + ", right child: " + rightChild);
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
    System.out.print("Enter the depth and ball number: ");
    while (numTests-- > 0) {
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
