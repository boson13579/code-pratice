package Java.A;

import java.util.Scanner;

public class A2_110502529 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int num = in.nextInt();

        String b = in.next();

        in.close();

        for(int i=0 ; i<(num-1) ; i++){

            for(int t=i ; t<num-1 ; t++)
                System.out.print(" ");

            System.out.print(b.charAt(0));

            for(int t=i ; t>0 ; t--)
                System.out.print(b.charAt(1));

            for(int t=i ; t>0 ; t--)
                System.out.print(b.charAt(1));

            System.out.print(b.charAt(0) + "\n");

        }
        for(int x=0 ; x<num*2 ; x++)
            System.out.print(b.charAt(0));

        System.out.println("\n");
    }

}
