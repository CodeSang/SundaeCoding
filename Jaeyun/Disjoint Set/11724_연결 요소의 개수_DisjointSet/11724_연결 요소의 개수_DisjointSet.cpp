#include<iostream>
#include<vector>

using namespace std;

vector<int> p(10001);
vector<int> m_rank(10001);
int N, M;


void Initialize() {
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
}
int Find(int idx) {
	if (idx == p[idx]) return idx;

	return p[idx] = Find(p[idx]);
}
void Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	if (u == v) return;

	if (m_rank[u] > m_rank[v]) swap(u, v);
	p[u] = v;

	if (m_rank[u] == m_rank[v]) ++m_rank[v];
}

int main() {
	int ans = 0;

	int u, v;
	cin >> N >> M;

	Initialize();

	while (M--) {
		cin >> u >> v;

		Union(u, v);
	}

	for (int i = 1; i <= N; i++) {
		if (p[i] == i) ans++;
	}

	cout << ans << endl;
}