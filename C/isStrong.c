#include<stdio.h>

int fact(int n)
{
    int f=1;
    int i=2;
    while(n>0)
    {
        f=f*n;
        n--;
    }
    return f;
}


int isStrong(int n)
{
    int num=n;
    int r=0,rem;
    while(n>0)
    {
        rem=n%10;
        r = r + fact(rem);
        n/=10;
    }
    if(num == r)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the no : ");
    scanf("%d",&n);

    if(isStrong(n)==1)
    {
        printf("%d is an armstrong no.\n",n);
    }
    else 
    {
        printf("%d is not an armstrong no.\n",n);
    }
    return 0;
}