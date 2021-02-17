// 바이러스 
#include<iostream>
#include<queue>
using namespace std;

int connect[101][101] = { 0 };
int visit[101] = { 0 };

int bfs(int start) {
	queue<int> q;
	int count = 0;

	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < 101; i++) {
			if (connect[start][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;

				count++;
			}
		}
	}

	return count;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int com, pair;
	cin >> com >> pair;
	for (int i = 0; i < pair; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		connect[num1][num2] = connect[num2][num1] = 1;
	}

	cout << bfs(1) << "\n";

	return 0;
}