#include<stdio.h>
#include<stdlib.h>
main()
{
	int a,f=1,num;
    printf("\t\t\t FACTORIAL PROGRAM");
    printf("\nEnter the number whose Factorial has to be found: ");
	scanf("%d",&a);
	num=1;
	while(num<=a)
	{
		f=f*num;
		num++;
	}
	printf("\nThe Factorial of %d is: %d",a,f);
}