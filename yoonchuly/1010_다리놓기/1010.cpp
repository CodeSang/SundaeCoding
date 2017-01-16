#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> bridge;
int main()
{
	int test_case;
	cin >> test_case;


	int n, m;
	for (int i = 0; i < 31; i++)
	{
		bridge.push_back(vector<int>());

		for (int j = 0; j < 31; j++)
		{
			bridge[i].push_back(0);
		}
	}

	bridge[0][0] = 1;

	for (int i = 1; i < 31; i++)
	{
		bridge[0][i] = 1;
		bridge[i][i] = 1;
	}

	for (int i = 1; i < 31; i++)
	{
		for (int j = 2; j < 31; j++)
		{
			bridge[i][j] = bridge[i - 1][j - 1] + bridge[i][j - 1];
		}
	}

	for (int i = 0; i < test_case; i++)
	{
		cin >> n;
		cin >> m;
		
		cout << bridge[n][m] << endl;
	}

	return 0;
}
