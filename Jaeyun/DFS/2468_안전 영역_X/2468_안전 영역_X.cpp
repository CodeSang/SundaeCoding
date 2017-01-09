#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> node(101, vector<int>(101));
vector<vector<int>> temp(101, vector<int>(101));
vector<int> safe(3000, 0);

int N, h=INT_MAX, H=INT_MIN;


void Input() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node[i][j];
			if (node[i][j] > H) H = node[i][j];
			if (node[i][j] < h) h = node[i][j];
		}
	}
}
void DFS(int x, int y) {
	// cout << "(x : " << x << ", y : " << y << ") : " << temp[y][x] << endl;
	temp[y][x] = 0;
	
	if (x - 1 > 0 && (temp[y][x - 1] > h)) {
		DFS(x - 1, y);
	}
	if (x + 1 <= N && (temp[y][x + 1] > h)) {
		DFS(x + 1, y);
	}
	if (y - 1 > 0 && (temp[y - 1][x] > h)) {
		DFS(x, y - 1);
	}
	if (y + 1 <= N && (temp[y + 1][x] > h)) {
		DFS(x, y + 1);
	}

}
int main() {
	int field[10] = { 0 };
	

	Input();
	int hh = h;

	while(h < H) {
		temp = node;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (temp[i][j] > h) {
					field[h]++;
					DFS(i, j);
				}
			}
		}
		h++;
	}
	for(int i=hh; i<=H; i++)
		cout  << field[i] << endl;

	return 0;
}