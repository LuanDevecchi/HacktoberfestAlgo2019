import java.util.*;
import java.io.*;
public class CollatzSequence
{
   public static void main(String[] args)
   {
      Scanner input = new Scanner(System.in);
      System.out.println("Start at what number?");
      int n = input.nextInt();
      System.out.println("\nThat Collatz Sequence was "+collatz(n,0)+" long!");
   }
   public static int collatz(int n, int count)
   {
      if(n==1) {
         System.out.print("1");
         return count;
      }
      else {
         if(n%2==0) {
            System.out.print(n+"-");
            count = collatz(n/2,count+1);
         }
         else {
            System.out.print(n+"-");
            count = collatz((n*3)+1,count+1);
         }
      }
      return count;
   }
}