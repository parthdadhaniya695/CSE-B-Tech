// 7. w.a.p. to find factors of a given number.

import java.util.Scanner;

public class Facters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number:");
        int n = sc.nextInt();
        for(int i=1;i<=n;i++){
            if(n%i==0){
                System.out.println(i+ " ");
            }
        }
    }
}
