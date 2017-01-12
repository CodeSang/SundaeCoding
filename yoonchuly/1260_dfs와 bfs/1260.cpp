#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

bool visited[1001];
void setVisited(bool);
void searchDFS(vector<vector<int>>, int);
void searchBFS(vector<vector<int>>, int);
vector<int> route;

int main()
{
	vector<vector <int>> edge;

	int size;
	cin >> size;
	for (int i = 0; i <= size; ++i)
		edge.push_back(vector<int>());

	cin >> size;
	int start;
	cin >> start;
	for (int i = 0; i < size; ++i)
	{
		int pt1, pt2;
		cin >> pt1;
		cin >> pt2;
		edge[pt1].push_back(pt2);
		edge[pt2].push_back(pt1);
	}
	for (int i = 0; i<edge.size(); ++i)
		sort(edge[i].begin(), edge[i].end());

	route.clear();
	setVisited(false);
	searchDFS(edge, start);
	for (int i = 0; i < route.size(); ++i)
		cout << route[i] << " ";


	cout << endl;
	route.clear();
	setVisited(false);
	searchBFS(edge, start);
	for (int i = 0; i < route.size(); ++i)
		cout << route[i] << " ";


	return 0;
}

void setVisited(bool value)
{
	for (int i = 0; i < 1001; ++i)
		visited[i] = value;
}
void searchDFS(vector<vector<int>> edge, int start)
{
	if (!visited[start])
	{
		route.push_back(start);
		visited[start] = true;
		for (int i = 0; i<edge[start].size(); ++i)
			searchDFS(edge, edge[start][i]);
	}
}
void searchBFS(vector<vector<int>> edge, int start)
{
	route.push_back(start);
	visited[start] = true;

	for (int i = 0; i < route.size(); i++)
	{
		for (int j = 0; j < edge[route[i]].size(); j++)
		{
			if (!visited[edge[route[i]][j]])
			{
				route.push_back(edge[route[i]][j]);
				visited[edge[route[i]][j]] = true;
			}
		}
	}

}
