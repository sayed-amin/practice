package Java.ArrayProblems;

import java.util.Scanner;

public class SquareOfSortedArrays {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long[] ans = new long[n];
        int temp= a.length;
        // Input array
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        int i = 0, j = n - 1, k = n - 1;
        
        // Two pointer approach
        while(i <= j) {
            long leftSquare = a[i] * a[i];
            long rightSquare = a[j] * a[j];
            
            if(leftSquare > rightSquare) {
                ans[k--] = leftSquare;
                i++;
            } else {
                ans[k--] = rightSquare;
                j--;
            }
        }
        
        // Output result
        for(long x : ans) {
            System.out.print(x + " ");
        }
        System.out.println();
        
        sc.close();
    }
}