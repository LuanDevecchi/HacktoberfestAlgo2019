#include <stdio.h>
#include<math.h>

 void towers(int, char, char, char);
 int main()
{
 int n, x=0;
  printf("Enter the number of disks : ");

    scanf("%d", &n);

    printf("The sequence of moves involved in the Tower of Hanoi are :\n");

    towers(n, 'A' , 'B', 'C');
    x=(pow(2,n)-1);
    printf("\nno of steps involved in process is : %d  \n ", x);

    return 0;    }

void towers(int n, char a, char b, char c)

{
   if(n>0)

   { towers(n-1, a , c, b);

    printf("\n Move disk %d from peg %c to peg %c", n, a, c);

    towers(n-1, b,a,c);
}
  }
