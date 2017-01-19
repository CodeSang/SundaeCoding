#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define M 2*1e7
vector<vector<int>> cost(17, vector<int>(17));
vector<vector<int>> dp(17, vector<int>(1<<17, M));
int N, start;

int DP(int src, int visit) {
	if (visit == 0) { 
		if (cost[src][start] == 0)
			return M;
		else
			return cost[src][start];
	}
	if (dp[src][visit] != M) return dp[src][visit];
	
	for (int i = 1; i < N; i++) {
		int visited = !((visit >> (i - 1)) % 2);
		int newVisit = visit & ~(1 << (i - 1));
		if (!visited && cost[src][i])
			dp[src][visit] = min(dp[src][visit], cost[src][i] + DP(i, newVisit));
	}

	
	return dp[src][visit];
}

int main() {
	int st = M, cmp;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		start = i;
		int visit = ((1 << N) - 1)&~(1 << (i - 1));
		if(cmp = DP(i, visit))
			st = min(st, cmp);
	}

	cout << st << endl;
	
	return 0;
}