#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;
void change_zero(vector<vector<int>>&, int, int);
int numArea;

vector<vector<vector<int>>> bachu;
int main()
{
	int test_case;

	cin >> test_case;
	int width;
	int height;

	for (int i = 0; i < test_case; ++i)
	{
		cin >> width;
		cin >> height;

		vector<vector<int>> baechu;
		for (int r = 0; r < height; ++r)
		{
			baechu.push_back(vector<int>());
			for (int c = 0; c < width; ++c)
				baechu[r].push_back(0);
		}

		int numBaechu = 0;
		cin >> numBaechu;
		for (int j = 0; j < numBaechu; ++j)
		{
			int r, c;
			cin >> c;
			cin >> r;
			baechu[r][c] = 1;
		}

		numArea = 0;
		for (int r = 0; r < height; ++r)
		{
			for (int c = 0; c < width; ++c)
			{
				if (baechu[r][c] == 1)
				{
					numArea += 1;
					change_zero(baechu, r, c);
				}
			}
		}
		cout << numArea << "\n";
	}
}

void change_zero(vector<vector<int>> &baechu, int r, int c)
{
	baechu[r][c] = 0;
	if (r + 1 < baechu.size() && baechu[r + 1][c] == 1)
		change_zero(baechu, r + 1, c);
	if (r - 1 >= 0 && baechu[r - 1][c] == 1)
		change_zero(baechu, r - 1, c);
	if (c + 1 < baechu[0].size() && baechu[r][c + 1] == 1)
		change_zero(baechu, r, c + 1);
	if (c - 1 >= 0 && baechu[r][c - 1] == 1)
		change_zero(baechu, r, c - 1);
}