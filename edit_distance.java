package dp;

import java.util.Scanner;

public class edit_distance {
	public static Scanner scn = new Scanner(System.in);     

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String a=scn.nextLine();
		String b=scn.nextLine();
		System.out.println(edit(a,b));
	}
public static int edit(String a,String b){
	
	int ans[][]=new int[a.length()+1][b.length()+1];
	for(int i=0;i<a.length()+1;i++){
		ans[i][0]=i;
	}
	for(int i=0;i<b.length()+1;i++){
		ans[0][i]=i;
	}
	for(int i=1;i<a.length()+1;i++){
		
		for(int j=1;j<b.length()+1;j++){
			
			if(a.charAt(i-1)==b.charAt(j-1)){
				ans[i][j]=ans[i-1][j-1];
			}else{
				ans[i][j]=1+Math.min(ans[i-1][j-1],Math.min(ans[i-1][j], ans[i][j-1]));
			}
		}
	}
	return ans[a.length()][b.length()];
}
}
