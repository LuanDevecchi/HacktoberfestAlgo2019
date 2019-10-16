#include<stdio.h>
int main(){
int a[100],element,i,n;
printf("Enter The No Of Elements You Want To Enter: ");
scanf("%d",&n);
printf("Enter The Elements: ");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("Enter The Element You Want To Search: ");
scanf("%d",&element);
for(i=0;i<n;i++){
if(element==a[i]){
printf("Element Is Found at position %d",i+1);
break;
}
else{
        if(i==n-1){
            printf("Element is not found");
        }
        else{
            continue;
        }

}
}
return 0;
}
