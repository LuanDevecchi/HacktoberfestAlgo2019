#include <bits/stdc++.h>
using namespace std;

void countingLexographically(int n, int k) {
	if( n < k ) {
		return;
	}

	for(int i = 0; i < 10; i++ ) {
		if( k <= n) {
			cout<<k<<" ";
			k *= 10;
			countingLexographically(n, k); // counting from k to n
			k /= 10;
			k++;
			if( k % 10 == 0) return;	
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int n;
cin>>n;

cout<<"0 ";
countingLexographically(n, 1);
return 0;
}