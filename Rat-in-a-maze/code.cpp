#include <bits/stdc++.h>
using namespace std;

int found = 0;

void printPath( char a[][1005], int n, int m ) {
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			if( a[i][j] != '1' ) {
				cout<<"0"<<" ";
			}else {
				cout<<"1"<<" ";
			}
		}
		cout<<endl;
	}
}

void rightMostPath(char maze[][1005], int n, int m, int r, int c ) {
	if( maze[n -1][m - 1] == '1' ) {
		printPath(maze, n, m );
		found = 1;
		return;
	}

	// once the rightmost path is discovered stop recursion
	if( found == 0 ) {
		// move right
		if( maze[r][c+1] != 'X' && r <= n - 1  && c <= m - 1 ) {
			maze[r][c + 1] = '1';
			rightMostPath(maze, n, m, r, c + 1);
			maze[r][c+1] = '0';
		}

		// move bottom
		if( maze[r+1][c] != 'X' && r <= n - 1  && c <= m - 1 ) {
			maze[r + 1][c] = '1';
			rightMostPath(maze, n, m, r + 1, c);
			maze[r + 1][c] = '0';
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
char maze[1005][1005];    
int n,m;

cin>>n>>m;

for( int i = 0; i < n; i++ ) {
	for( int j = 0; j < m; j++ ) {
		cin>>maze[i][j];
	}
}

maze[0][0] = '1'; 
rightMostPath(maze, n, m, 0, 0);
if( found == 0 ) cout<<"-1";
return 0;
}