#include<iostream>
#include<vector>
using namespace std;

int N, M, K, n;	// M:�� ���� Ƚ��, K:���� �� ���ϴ� Ƚ��
int a, b, c;
vector<int> v;
vector<int> tree;

void Fenwick_update(int n, int sum) {
	int temp;
	while (n < tree.size()) { // �Ǵ� for������ ������Ű�� ���
		tree[n] += sum;
		temp = n & -n;		
		n += temp;
	}
}
int Sum(int n) {
	int sum = 0;
	while (n>0)
	{
		sum += tree[n];
		int temp = n & -n;
		n -= temp;
	}
	return sum;
}
int main() {
	cin >> N >> M >> K;
	tree.resize(N + 1);
	v.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
		Fenwick_update(i, v[i]);
	}


	for (int i = 0; i < M + K; i++) {

		cin >> a >> b >> c;
		if (a == 1) {
			Fenwick_update(b, c - tree[b]);
		}
		else if (a == 2)
			cout << Sum(c) - Sum(b - 1) << endl;
	}

	return 0;
}