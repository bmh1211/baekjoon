// ¿Ø±‚≥Û πË√ﬂ

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int baechu[51][51];
bool isVisited[51][51];

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	isVisited[start_x][start_y] = true;

	while (!q.empty()) {
		start_x = q.front().first;
		start_y = q.front().second;
		q.pop();

		if (start_x < 49 && baechu[start_x + 1][start_y] == 1 && isVisited[start_x + 1][start_y] == false) {
			q.push(make_pair(start_x + 1, start_y));
			isVisited[start_x + 1][start_y] = true;
		}
		if (start_x > 0 && baechu[start_x - 1][start_y] == 1 && isVisited[start_x - 1][start_y] == false) {
			q.push(make_pair(start_x - 1, start_y));
			isVisited[start_x - 1][start_y] = true;
		}
		if (start_y < 49 && baechu[start_x][start_y + 1] == 1 && isVisited[start_x][start_y + 1] == false) {
			q.push(make_pair(start_x, start_y + 1));
			isVisited[start_x][start_y + 1] = true;
		}
		if (start_y > 0 && baechu[start_x][start_y - 1] == 1 && isVisited[start_x][start_y - 1] == false) {
			q.push(make_pair(start_x, start_y - 1));
			isVisited[start_x][start_y - 1] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(baechu, 0, sizeof(baechu));
		memset(isVisited, false, sizeof(isVisited));

		int M, N, K, count = 0;
		cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			int num1, num2;
			cin >> num1 >> num2;

			baechu[num1][num2] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (baechu[i][j] == 1 && isVisited[i][j] == false) {
					bfs(i, j);
					isVisited[i][j] = true;
					count++;
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}