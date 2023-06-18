import java.util.Scanner;

public class Dropping {
    static int bound;

        public static int getFinalPosition(int n, int ball) {
       if(n>=bound)
       {
           return n;
       }
         int left=(n<<1);
         int right=left+1;
        if(ball%2==0)
        {
            return getFinalPosition(right,ball/2);
        }
        else
        {
            return getFinalPosition(left,ball/2+1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of test cases: ");
        int numTests = scanner.nextInt();

        while (numTests-- > 0) {
            System.out.print("Enter the depth and ball number: ");
            int deep = scanner.nextInt();
            int ball = scanner.nextInt();
            bound=1<<(deep-1);

            int ans = getFinalPosition(1, ball);
            System.out.println("Final position: " + ans);
        }
    }

}
