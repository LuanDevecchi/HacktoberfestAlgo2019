#include<stdio.h>
int sum(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
	int sum1 =0,sum2 =0,sum3 =0;
	for(int i = 0; i < n1; i++)
		sum1 = sum1 + arr1[i];
	for(int i = 0; i < n2; i++)
		sum2 = sum2 + arr1[i];
	for(int i = 0; i < n3; i++)
		sum3 = sum3 + arr1[i];
	int top1= 0,top2= 0,top3 =0;
	while(1){
		if(sum1 == sum2 && sum2 == sum3)
			return sum1;
		if(top1 == n1 || top2 == n2 || top3 == n3)
			return 0;
		if(sum1 >= sum2 && sum1 >=sum3)
			sum1 -= arr1[top1++];
		else if(sum2 >= sum1 && sum2 >=sum3)
			sum2 -= arr2[top2++];
		else if(sum3 >= sum2 && sum3 >=sum1)
			sum3 -= arr3[top3++];

	}
}
int main(){
	int arr1[5] = {1,2,3,4,5};
	int arr2[4] ={0,0,12,3};
	int arr3[2] = {11,12};
	int x = sum(arr1,arr2,arr3,5,4,3);
	printf("%d \n", x);
	return 0;
}