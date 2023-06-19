import java.util.Scanner;

public class Sorting {

    public static void printAlphabet(int n) {
        if (n > 0) System.out.print("a");
        if (n > 1) System.out.print(",b");
        if (n > 2) System.out.print(",c");
        if (n > 3) System.out.print(",d");
        if (n > 4) System.out.print(",e");
        if (n > 5) System.out.print(",f");
        if (n > 6) System.out.print(",g");
        if (n > 7) System.out.print(",h");
    }

    public static void printBlankSpace(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(" ");
        }
    }

    public static void printArray(char[] arr, int n) {

        System.out.print("writeln(");
        for (int i = 0; i < n; i++) {
            if (i != 0) System.out.print(",");
            System.out.print(arr[i]);
        }
        System.out.println(")");
    }

    public static void generatePascalProgram(char[] arr, char[] currentArrangement, int n, int count) {
        char[] newCurrentArrangement = new char[10];
        System.arraycopy(currentArrangement, 0, newCurrentArrangement, 0, n);


        for (int i = 0; i < count; i++) {
            if (i == count - 1) {
                printBlankSpace(count - 1);
                System.out.println("else");
                if (count < n) {
                    generatePascalProgram(arr, newCurrentArrangement, n, count + 1);
                }
                if (count == n) {
                    printBlankSpace(count);
                    printArray(newCurrentArrangement, n);
                }
            } else {
                printBlankSpace(count - 1);
                if (i != 0) System.out.print("else ");
                System.out.println("if " + currentArrangement[count - i - 2] + " < " + arr[count - 1] + " then");
                if (count < n) {
                    generatePascalProgram(arr, newCurrentArrangement, n, count + 1);
                }
                if (count == n) {
                    printBlankSpace(count);
                    printArray(newCurrentArrangement, n);
                }
                char temp = newCurrentArrangement[count - i - 2];
                newCurrentArrangement[count - i - 2] = newCurrentArrangement[count - i - 1];
                newCurrentArrangement[count - i - 1] = temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testcase = scanner.nextInt();
        boolean isFirstTestcase = false;

        for (int i = 0; i < testcase; i++) {
            int n = scanner.nextInt();
            if (isFirstTestcase) System.out.println();
            isFirstTestcase = true;
            System.out.println("program sort(input,output);");
            System.out.println("var");
            printAlphabet(n);
            System.out.println(": integer;");
            System.out.println("begin");
            System.out.print("  readln(");
            printAlphabet(n);
            System.out.println(");");

            char[] arr = new char[10];
            char[] currentArrangement = new char[10];
            arr[0] = 'a';
            arr[1] = 'b';
            arr[2] = 'c';
            arr[3] = 'd';
            arr[4] = 'e';
            arr[5] = 'f';
            arr[6] = 'g';
            arr[7] = 'h';
            currentArrangement[0] = 'a';
            currentArrangement[1] = 'b';
            currentArrangement[2] = 'c';
            currentArrangement[3] = 'd';
            currentArrangement[4] = 'e';
            currentArrangement[5] = 'f';
            currentArrangement[6] = 'g';
            currentArrangement[7] = 'h';
            if (n > 1) {
                generatePascalProgram(arr, currentArrangement, n, 2);
            } else {
                System.out.println("  writeln(a);");
            }
            System.out.println("end.");
        }
    }
}
