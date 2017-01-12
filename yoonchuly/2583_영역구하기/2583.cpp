#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;
void check_edge(vector<vector<int>> &, int, int);
void s(int, int, int, int);
vector<vector<int>> edge;
vector<int> amount;
int result = 0;
int main()
{
	int m, n, k;
	cin >> m;
	cin >> n;
	cin >> k;

	for (int i = 0; i < m; i++)
	{
		edge.push_back(vector<int>());
		for (int j = 0; j < n; j++)
		{
			edge[i].push_back(0);
		}
	}
	
	int x_1, y_1, x_2, y_2;

	for (int i = 0; i < k; i++)
	{
		cin >> x_1;
		cin >> y_1;
		cin >> x_2;
		cin >> y_2;
		
		s(x_1, y_1, x_2, y_2);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j] == -1)
				continue;
			if (edge[i][j] == 0)
			{
				amount.push_back(0);
				check_edge(edge, i, j);
				result++;
			}
		}
	}

	cout << result << endl;
	sort(amount.begin(), amount.end());

	for (int i = 0; i < amount.size(); i++)
	{
		cout << amount[i] << " ";
	}

	return 0;
}
void s(int x_1, int y_1, int x_2, int y_2)
{
	for (int i = x_1; i <= x_2 -1; i++)
	{
		for (int j = y_1; j <= y_2 -1; j++)
		{
			edge[j][i] = 1; //문제랑 일치시킬려고..
		}
	}
}

void check_edge(vector<vector<int>> &edge, int i, int j)
{
	edge[i][j] = -1;
	amount[result]++;

	if (i + 1 < edge.size() && edge[i + 1][j] == 0)
		check_edge(edge, i + 1, j);
	if (i - 1 >= 0 && edge[i - 1][j] == 0)
		check_edge(edge, i - 1, j);
	if (j + 1 < edge[0].size() && edge[i][j + 1] == 0)
		check_edge(edge, i, j + 1);
	if (j - 1 >= 0 && edge[i][j - 1] == 0)
		check_edge(edge, i, j - 1);
}//배추랑 똑같음 dfs(재귀)