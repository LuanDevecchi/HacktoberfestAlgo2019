/* Program to evaluate a postfix expression using stack. Input is a string example :- "162+*8-"(without quotes) and it output answer to this postfix expression. */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

  stack<int>st; 
  string s;
  cin>>s; 
  int n =s.length(); 
  int ans =0; 
  for(int i=0; i<n; i++){
      if(s[i] >='0' && s[i] <='9')st.push(s[i]-'0');
      else{
          if(st.size() >=2){
                   int x = st.top(); 
          st.pop();
          int y = st.top(); 
          st.pop(); 

          switch(s[i]){
              case '*': ans = x*y;
                      break;
              case '/': ans = y/x;
                      break;
                case '+' : ans = x+y;
                        break;
                case '-' : ans = y-x; 
                        break; 
          }
          st.push(ans);
          }


      }
  }
  cout<<st.top()<<"\n";
	
	return 0;
}
