#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string cmd;
	int T, N, x, err, size;
	cin >> T;
	
	while (T--) {
		deque<int> dq;
		cin >> cmd;
		scanf("%d\n", &N);
		
		scanf("[");
		while (N>1) {
			if(N>1) {
				scanf("%d,", &x);
				dq.push_back(x);
			}
			else {
				scanf("%d]", &x);
				dq.push_back(x);
			}
			N--;
		}
		
		
		
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') {
				cout << "REVERSE\n";
				reverse(dq.begin(), dq.end());
			}
			else if (cmd[i] == 'D') {
				cout << "POP\n";
				if (!dq.empty()) {
					dq.pop_front();
				}
				else {
					err = 1;
					break;
				}
			}
		}

		size = dq.size();
		cout << "size : " << size << endl;

		if(err == 0) {
			cout << "결과 : ";
			cout << "[";
			for (int i = 1; i < size; i++) {
				cout <<	dq.front() << ",";
				dq.pop_front();
			}
			if (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}
			cout << "]\n";
		}
		else {
			err = 0;
			cout << "결과 : error\n";
		}
	}
}