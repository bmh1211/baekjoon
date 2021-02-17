// DFS와 BFS

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int connect[1001][1001] = { 0 }; // 1이 연결이 존재하는것
int visit[1001] = { 0 }; // 1이 방문했다는것

void dfs(int start) {
	visit[start] = 1;
	
	cout << start << " ";

	for (int i = 0; i < 1001; i++) {
		if (connect[start][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	
	visit[start] = 1;
	q.push(start);

	while (!q.empty()) {
		start = q.front();
		cout << start << " ";
		q.pop();
		for (int i = 0; i < 1001; i++) {
			if (connect[start][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		connect[num1][num2] = connect[num2][num1] = 1;
	}

	dfs(V);
	for (int i = 0; i < 1001; i++) {
		visit[i] = 0;
	}
	cout << "\n";
	bfs(V);

	return 0;
}