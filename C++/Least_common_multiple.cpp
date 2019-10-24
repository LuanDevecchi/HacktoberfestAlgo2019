#include <iostream>
int gcd_new(int a,int b){
    if(b==0){
        return a;
    }
    int gcd=a%b;

    return gcd_new(b,gcd);
}

long long lcm_new(int a , int b){
    int val=gcd_new(a,b);
   
    long long int mul=((long long int)a)*((long long int)b);

    long long int lcm= mul/val;
    return lcm;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  
  std::cout << lcm_new(a, b) << std::endl;
  return 0;
}
