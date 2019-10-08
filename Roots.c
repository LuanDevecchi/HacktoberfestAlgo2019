#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, root_x1, root_x2, delta,i;
    printf("Insirt the valor a: \n");
    scanf("%d",&a);
    printf("Insirt the valor b: \n");
    scanf("%d",&b);
    printf("Insirt the valor c: \n");
    scanf("%d",&c);

    delta=(pow(b,2)-4*a*c);

    if(delta < 0)
    {
        i = sqrt(-delta);
        root_x1=(-b/(2*a));
        root_x2=(delta/(2*a));
        printf("The equation have root would imagine\n, part real %d, part would imagine %d\n",root_x1,root_x2);
    }
    else{
        if(delta == 0)
        {
            root_x1=(-b+sqrt(delta))/2*a;
            root_x2=(-b-sqrt(delta))/2*a;
            printf("The equation have one root = %d\n",root_x1);
        }
    else{
            if(delta > 0)
            {
                root_x1=(-b+sqrt(delta))/2*a;
                root_x2=(-b-sqrt(delta))/2*a;
                printf("The equation have two roots = %d %d.\n",root_x1,root_x2);
            }
        }
    }

}
