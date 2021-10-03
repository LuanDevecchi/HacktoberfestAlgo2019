#include<stdio.h>
float circle_area(float radius);
void main()
{
    float r;
    float area=0;
    printf("Enter the radius of circle:");
    scanf("%f",&r);
    area=circle_area(r);
    printf("The area is:%.2f",area);
}

float circle_area(float radius)
{
  return (radius * radius) * 3.1415;
}
