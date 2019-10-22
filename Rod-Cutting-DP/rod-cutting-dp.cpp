#include <bits/stdc++.h>
using namespace std;

int profit[200];

// Top Down DP
int rodCutDP( int a[], int n ) {
	int max_profit = INT_MIN;
	if( n <= 0 ) { // rod of size 0 or less has no value
		return 0;
	}
	for( int i = 0; i < n; i++ ) {
		if( profit[n - i - 1] == -1 ) {
			max_profit = max( max_profit, a[i] + rodCutDP(a, n - i - 1));
			profit[n - i - 1] = max_profit - a[i];
		} else {
			max_profit = max( max_profit, a[i] + profit[n - i - 1] );
		}
	}

	return max_profit;
}

// recursive approach
int rodCut( int a[], int n ) {
	int max_profit = INT_MIN;
	if( n <= 0 ) { // rod of size 0 or less has no value
		return 0;
	}

	// a rod of length n can have n - 1 cut positions
	for( int i = 0; i < n; i++ ) {
		max_profit = max( max_profit, a[i] + rodCut(a, n - i - 1));
	}
	return max_profit;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int n;
cin >> n;
int *a = new int[n];
for( int i = 0; i < n; i++ ) {
	cin >> a[i];
}
for( int i = 0; i < 200; i++ ) {
	profit[i] = -1;
}

// cout << rodCut( a, n ); 
cout << rodCutDP( a, n );
return 0;
}