// C/C++ program to find maximum number of
// games played by winner
#include <bits/stdc++.h>
using namespace std;

// method returns maximum games a winner needs
// to play in N-player tournament
int maxGameByWinner(int N)
{
	int dp[N];

	// for 0 games, 1 player is needed
	// for 1 game, 2 players are required
	dp[0] = 1;
	dp[1] = 2;

	// loop until i-th Fibonacci number is
	// less than or equal to N
	int i = 2;
	do {
		dp[i] = dp[i - 1] + dp[i - 2];
	} while (dp[i++] <= N);

	// result is (i - 2) because i will be
	// incremented one extra in while loop
	// and we want the last value which is
	// smaller than N, so one more decrement
	return (i - 2);
}

// Driver code to test above methods
int main()
{
	int N = 10;
	cout << maxGameByWinner(N) << endl;
	return 0;
}

