package Java.ArrayProblems;

import java.util.HashMap;
import java.util.Scanner;

public class TreasureRoom {
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int w=sc.nextInt();
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<n;i++){
            int x= sc.nextInt();
            int needed=w-x;

            if(map.containsKey(needed)){
                System.out.println(map.get(needed)+1+" "+(i+1));
                return ;
            }
            if(!map.containsKey(needed)){
                map.put(x,i);
            }
        }
        System.out.println(-1);
    }
}
