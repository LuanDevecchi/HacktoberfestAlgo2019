#include <bits/stdc++.h>
using namespace std;

int lcs3strings( string a, string b, string c ) {
	int l = a.length();
	int m = b.length();
	int n = c.length();

	int dp[l + 1][m + 1][n + 1];

	for( int i = 0; i <= l; i++ ) {
		for( int j = 0; j <= m; j++ ) {
			for( int k = 0; k <= n; k++ ) {
				if( i == 0 || j == 0 || k == 0 ) {
					dp[i][j][k] = 0;
				}else if( a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1] ) {
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				}else {
					dp[i][j][k] = max( max(dp[i - 1][j][k], dp[i][j-1][k]), dp[i][j][k-1] );
				}
			}
		}
	} 
	return dp[l][m][n];
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string a, b, c;
cin >> a >> b >> c;

cout << lcs3strings( a, b, c );
return 0;
}