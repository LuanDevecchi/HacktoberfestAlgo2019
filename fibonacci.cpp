#include <cstdio>

int fib( const int n )
{
	if ( n <= 1 ) return n;

	return fib( n - 1 ) + fib( n - 2 );
}

int main()
{
	for ( auto i = 0; i < 20; ++i )
		printf( "%d\n", fib( i ) );
}
