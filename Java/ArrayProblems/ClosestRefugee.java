package Java.ArrayProblems;


import java.util.Scanner;

public class ClosestRefugee {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();

        int[] a= new int[n+1];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        
        boolean[] present= new boolean[n+1];
        for(int i=0;i<n;i++){
            if(a[i]>0 && a[i]<=n)
            present[a[i]]=true;
        }
        for(int i=1;i<n;i++){
            if(present[i]!=true)
           { System.out.println(i);
            break;}
        }
        sc.close();
    }
}
