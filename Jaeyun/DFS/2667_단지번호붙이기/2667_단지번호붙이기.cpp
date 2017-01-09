#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> node(26, vector<int>(26));
vector<int> n_danji(200);
int danji = 0;

void Input() {
	char c;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			//cout << "c : " << endl;
			if (c == '1') {
				node[i][j] = 1;
			}
			else {
				node[i][j] = 0;
			}
		}
	}
}

void DFS(int y, int x) {
	node[y][x] = 0;
	n_danji[danji]++;
	if (x + 1 <= N && node[y][x + 1] == 1) {
		node[y][x + 1] = danji;
		DFS(y, x + 1);
	}
	if (x - 1 > 0 && node[y][x - 1] == 1) {
		node[y][x - 1] = danji;
		DFS(y, x - 1);
	}
	if (y + 1 <= N && node[y + 1][x] == 1) {
		node[y+1][x] = danji;
		DFS(y + 1, x);
	}
	if (y - 1 > 0 && node[y - 1][x] == 1) {
		node[y - 1][x] = danji;
		DFS(y - 1, x);
	}
}


int main() {

	Input();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (node[i][j] == 1) {
				danji++;
				DFS(i, j);
			}
		}
	}
	
	cout << danji << endl;

	sort(n_danji.begin()+1, n_danji.begin() + danji+1);

	if (danji == 0) cout << "0" << endl;
	else {
		for (int i = 1; i <= danji; i++) {
			cout << n_danji[i] << " " << endl;
		}
	}


	return 0;
}
