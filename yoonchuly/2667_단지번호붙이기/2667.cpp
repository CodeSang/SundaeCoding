#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;
void check_jip(vector<vector<int>> &, int, int);
vector <vector <int>> edge;
vector <vector <int>> visited;
vector <int> danji_amount;
int result = 0;
int main()
{
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		edge.push_back(vector<int>());
		for (int j = 0; j < size; j++)
		{
			edge[i].push_back(0);
		}
	}// 0으로 초기화

	string jip;

	for (int i = 0; i < size; i++)
	{
		cin >> jip;
		for (int j = 0; j < jip.size(); j++)
		{
			edge[i][j] = jip[j] - 48;
		}
	} // string 으로 받은거 하나씩 edge에 저장

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (edge[i][j] == 1)
			{
				danji_amount.push_back(0);
				check_jip(edge, i, j);
				result++;
			}
		}
	}

	cout << result << endl;
	sort(danji_amount.begin(), danji_amount.end());

	for (int i = 0; i < danji_amount.size(); i++)
	{
		cout << danji_amount[i] << endl;
	}
	

	return 0;
}
void check_jip(vector<vector<int>> &jip, int i, int j)
{
	jip[i][j] = 0;
	danji_amount[result]++;
	if (i + 1 < jip.size() && jip[i + 1][j] == 1)
		check_jip(jip, i + 1, j);
	if (i - 1 >= 0 && jip[i - 1][j] == 1)
		check_jip(jip, i - 1, j);
	if (j + 1 < jip[0].size() && jip[i][j + 1] == 1)
		check_jip(jip, i, j + 1);
	if (j - 1 >= 0 && jip[i][j - 1] == 1)
		check_jip(jip, i, j - 1);
}//배추랑 똑같음 dfs(재귀)