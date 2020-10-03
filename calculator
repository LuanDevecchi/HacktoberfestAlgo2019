#include <stdio.h>
#include <stdlib.h>

int main()
{
     int y,z;
    int cal;
    while(1)
    {
    printf("\nEnter the 1st number:- ");
    scanf("%d",&z);
    printf("Enter the 2nd number:- ");
    scanf("%d",&y);
    printf("\n \n For Add Enter>> 1 \n For Subtract Enter>> 2 \n For Multiply Enter>> 3 \n For Divide Enter>> 4\n For Exit Enter>> 5 \n \n ");
    printf("Select your task:- ");
    scanf("%d",&cal);

        switch(cal)
        {
        case 1: z + y;
        printf(" %d\n", z + y);
            break;
        case 2:
            if(z>y)
            {
                z - y;
                printf(" %d \n", z - y );
            }
            else
                {
                 y - z;
                printf(" %d\n ", y - z);

                break;
        case 3: z *y;
        printf(" %d\n ",z*y );
        break;
        case 4:
            if(z>y){
                z/y;
            printf("%d\n", z/y);
            }
            else
             {
                 y/z;
                printf(" %d\n", y/z);
             }
            break;
            case 5: exit(0);
            default :
            printf("You have pressed a incorrect key");
            break;
                }
        }
   }
    return 0;
}
