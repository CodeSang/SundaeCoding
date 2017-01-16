#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> wine;
vector <int> dp(10001,0);
int main()
{
	int n;
	cin >> n;

	int temp;

	wine.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		wine.push_back(temp);
	}


	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];


	int result = 0;
	for (int i = 3; i <= n; i++)
	{
		result = max(wine[i] + dp[i - 2], dp[i - 1]);
		result = max(result, wine[i] + wine[i - 1] + dp[i - 3]);
		dp[i] = result;
	}

	cout << dp[n] << endl;

}