// 미로 탐색

#include<iostream>
#include<queue>
using namespace std;

char maze[101][101];
int weight[101][101];
bool isVisited[101][101];
int N, M;

// 동서남북 체크
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	isVisited[x][y] = true;

	// 시작위치의 가중치 1
	weight[0][0] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				if (maze[next_x][next_y] == '1' && isVisited[next_x][next_y] == false) {
					q.push(make_pair(next_x, next_y));
					isVisited[next_x][next_y] = true;

					// dp 적용 - 각 칸마다 얼만큼의 칸을 지나쳐왔는지 표시
					weight[next_x][next_y] = weight[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	bfs(0, 0);
	cout << weight[N - 1][M - 1] << "\n";

	return 0;
}