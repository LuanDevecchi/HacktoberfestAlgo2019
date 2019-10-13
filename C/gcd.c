#include<stdio.h>

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int gcd(int m, int n) {
	int opCount = 0;
	int div = min(m,n);
	while (div != 1) {
		opCount++;
		if (m % div == 0 && n % div == 0)
			break;
		div--;	 
	}
	printf("OpCount: %d\n", opCount);
	return div;
}

int main(int argc, char const *argv[])
{
	int num1;
	int num2;
	printf("Enter 2 nums: ");
	scanf("%d%d", &num1, &num2);
	printf("GCD is %d\n", gcd(num1, num2));
	return 0;
}
