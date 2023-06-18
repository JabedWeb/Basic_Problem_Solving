import java.util.Scanner;

public class Sorting {

    public static void printabc(int n) {
        if (n > 0) System.out.print("a");
        if (n > 1) System.out.print(",b");
        if (n > 2) System.out.print(",c");
        if (n > 3) System.out.print(",d");
        if (n > 4) System.out.print(",e");
        if (n > 5) System.out.print(",f");
        if (n > 6) System.out.print(",g");
        if (n > 7) System.out.print(",h");
    }

    public static void printblank(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(" ");
        }
    }

    public static void printarr(char ch[], int n) {
        System.out.print("writeln(");
        for (int i = 0; i < n; i++) {
            if (i != 0) System.out.print(",");
            System.out.print(ch[i]);
        }
        System.out.println(")");
    }

    public static void pascal_program(char ch[], char cur[], int n, int cnt) {
        char[] new_cur = new char[10];
        System.arraycopy(cur, 0, new_cur, 0, n);

        for (int i = 0; i < cnt; i++) {
            if (i == cnt - 1) {
                printblank(cnt - 1);
                System.out.println("else");
                if (cnt < n) {
                    pascal_program(ch, new_cur, n, cnt + 1);
                }
                if (cnt == n) {
                    printblank(cnt);
                    printarr(new_cur, n);
                }
            } else {
                printblank(cnt - 1);
                if (i != 0) System.out.print("else ");
                System.out.println("if " + cur[cnt - i - 2] + " < " + ch[cnt - 1] + " then");
                if (cnt < n) {
                    pascal_program(ch, new_cur, n, cnt + 1);
                }
                if (cnt == n) {
                    printblank(cnt);
                    printarr(new_cur, n);
                }
                char temp = new_cur[cnt - i - 2];
                new_cur[cnt - i - 2] = new_cur[cnt - i - 1];
                new_cur[cnt - i - 1] = temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testcase = scanner.nextInt();
        boolean ffff = false;

        for (int i = 0; i < testcase; i++) {
            int n = scanner.nextInt();
            if (ffff) System.out.println();
            ffff = true;
            System.out.println("program sort(input,output);");
            System.out.println("var");
            printabc(n);
            System.out.println(": integer;");
            System.out.println("begin");
            System.out.print("  readln(");
            printabc(n);
            System.out.println(");");

            char[] ch = new char[10];
            char[] cur = new char[10];
            ch[0] = 'a';
            ch[1] = 'b';
            ch[2] = 'c';
            ch[3] = 'd';
            ch[4] = 'e';
            ch[5] = 'f';
            ch[6] = 'g';
            ch[7] = 'h';
            cur[0] = 'a';
            cur[1] = 'b';
            cur[2] = 'c';
            cur[3] = 'd';
            cur[4] = 'e';
            cur[5] = 'f';
            cur[6] = 'g';
            cur[7] = 'h';
            if (n > 1) {
                pascal_program(ch, cur, n, 2);
            } else {
                System.out.println("  writeln(a);");
            }
            System.out.println("end.");
        }
    }
}
