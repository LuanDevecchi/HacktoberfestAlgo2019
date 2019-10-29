import java.util.*;
public class Main {
   static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		int array[]=takeinput();
		int posn = lins(array);
		System.out.println(posn);
	}
	public static int[] takeinput() {
		int array[] = null;
		int size = scn.nextInt();
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = scn.nextInt();
		}
		return array;
	}
	public static int lins(int[] arr) {
		int posn=-1;
		int num=scn.nextInt();
		for(int i=0;i<arr.length;i++) {
			if(arr[i]==num) {
				posn=i;
			
			    break;
			}
		}
		return posn;
	}

}

