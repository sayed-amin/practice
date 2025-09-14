package Java.ArrayProblems;

import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static int [] function(int []a, int sum)
{
     HashMap<Integer,Integer> map=new HashMap<>();
    for(int i=0;i<a.length;i++){

        for(int j=i+1;j<a.length;j++){
            
            int third_value=sum-a[i]-a[j];
            if(map.containsKey(third_value) && map.get(third_value)!=i && map.get(third_value)!=j){
                return new int[]{i,j,map.get(third_value)};
            }
            map.put(a[i],i);
        }
    }


    return null;
}    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        int w= sc.nextInt();
       
        int[] a= new int[n];

        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();

        }
        int[] triplets= function(a, w);

        if(triplets==null){
            System.out.println(-1);
        }else{
            for(int i=0;i<triplets.length;i++){
                System.out.print(triplets[i]+1+" ");
            }
        }
        
    }
}
