
#include<stdio.h>
int main(){
int a[100],c=0,mid,element,i,n,top,bottom;
printf("Enter The No Of Elements You Want To Enter: ");
scanf("%d",&n);
printf("Enter The Elements: ");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("Enter The Element You Want To Search: ");
scanf("%d",&element);
top=0;
bottom=n;
mid=((top+bottom)/2);
while(bottom>top){
if(a[mid]==element){
printf("Element Is Found");
c++;
break;
}
else if(a[mid]<element){
top=mid+1;
mid=((top+bottom)/2);
}
else{
bottom=mid-1;
mid=((top+bottom)/2);
}
}
if(c==0){
printf("Element Not Found");
}
return 0;
}
