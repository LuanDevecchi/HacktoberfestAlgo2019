#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

      int i,p,k,j,a[1000][1000];
      p=(2*n)-1;
      for(i=0;i<n;i++)
      {
          for(j=i;j<(p-(2*i)+i);j++)
          {
            for(k=i;k<(p-(2*i)+i);k++)
            {if((j==i)||(k==i)||(j==(p-(i+1)))||(k==(p-(i+1))))
                   a[j][k]=n-i;
          }}

      }
      for(i=0;i<p;i++)
      {
          for(j=0;j<p;j++)
          {
              printf("%d ",a[i][j]);
          }printf("\n");
      }
    return 0;
}

