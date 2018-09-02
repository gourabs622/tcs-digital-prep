/** PROBLEM STATEMENT:
Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

Examples:

Input n = 3
Output: 3
Explanation:
We need 3 tiles to tile the board of size  2 x 3. 
We can tile the board using following ways
1) Place all 3 tiles vertically. 
2) Place first tile vertically and remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically

Input n = 4
Output: 5
Explanation:
For a 2 x 4 board, there are 5 ways
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal
4) First 2 horizontal, remaining 2 vertical
5) Corner 2 vertical, middle 2 horizontal

LOGIC:
	count(n) = n if n = 1 or n = 2
	count(n) = count(n-1) + count(n-2) 
*/

#include <bits/stdc++.h>
using namespace std;

long int ways[100];

long int getWays(int n)
{
	// base case
	if (n <= 2)
		return n;
	
	// already solved
	if (ways[n] != -1)
		return ways[n];
	
	return ways[n] = getWays(n-1) + getWays(n-2);
}

int main(int argc, char *argv[])
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	// ways = new long int[n];
	memset(ways, -1, sizeof ways);

	cout << "Number of ways to tile " << n << " tiles: " << getWays(n) << endl;

	return 0;
}
