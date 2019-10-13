#include<stdio.h>
#include<stdlib.h>
int gcd(a,b){
	if(b == 0){
		return a;
	}
	else
		return gcd(b, a%b);
}
void rotation(int arr[], int k, int n){
	int g_c_d = gcd(k,n);
	for(int i = 0; i < g_c_d; i++){
		int temp = arr[i];
		int j = i;
		while(1){
			int x = j + g_c_d;
			if(x >= n)
				x = x- n;
			if(x == i)
				break;
			arr[j] = arr[x];
			j = x;
		}
		arr[j] = temp;
	}
}
int main(){
	int a[5] = {1,2,3,4,5};
	rotation(a,2,5);
	for(int i = 0; i < 5; i++){
		printf("%d \n", a[i]);
	}
	return 0;
}