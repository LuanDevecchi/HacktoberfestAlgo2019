// Comparing two strings

#include<stdio.h>
#include<conio.h>
void main()
{
	char s1[20],s2[20];
	int i,flag=0;
	clrscr();
	printf("Enter the first string:");
	gets(s1);
	printf("Enter the second string");
	gets(s2);

	for(i=0;s1[i]!='\0';i++)
	{
	       if(strlen(s1)!=strlen(s2))
	       {
		flag=1;
		break;
	       }

	       else if(s1[i]=s2[i])
			continue;
	       else
	       {
		flag=1;
		break;
	       }
	}

	if(flag==0)
		printf("The two strings are equal.");
	else
		printf("The strings are not equal");
	getch();
}
