#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> node(101, vector<int>(101));
vector<bool> visited(1001, true);
vector<bool> t_visited(1001, true);
int N, M;
vector<int> cnt(1001, 0);
void Input() {
	int u, v;

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
		visited[u] = false;
		visited[v] = false;
	}
}
void DFS(int v, int d) {
	t_visited[v] = true;
	cnt[v]++;
	if (v == d) return;
	for (auto iter : node[v]) {
		if (!t_visited[iter]) DFS(v, iter);
	}
}
int main() {

	Input();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			t_visited = visited;
			if (!t_visited[j])	DFS(i, j);
		}
	}
	for(int i=1; i<= N; i++) {
		cout << cnt[i] << " ";
	}
	cout << endl;
	
	getchar();
	getchar();
	return 0;
}
