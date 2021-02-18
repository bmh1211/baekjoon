// 토마토

#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> q;
int tomato[1001][1001];
bool isVisited[1001][1001];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tomato_total = 0;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		isVisited[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (tomato[nx][ny] == 0 && isVisited[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					isVisited[nx][ny] = true;
					tomato[nx][ny] = tomato[x][y] + 1;
				}
			}
		}

		// 출력 체크용
		/*cout << "\n=========================\n";
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << tomato[i][j] << " ";
			}
			cout << "\n";
		}*/
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 익은 토마토 : 1, 익지 않은 토마토 : 0, 빈칸 : -1
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];

			if (tomato[i][j] == 0)
				tomato_total++;
			else if (tomato[i][j] == 1)
				q.push(make_pair(i, j)); // 익은 토마토는 queue에 넣어줌
		}
	}
	
	if (tomato_total == 0)
		cout << 0 << "\n";
	else {
		bfs();

		int result = tomato[0][0];
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (tomato[i][j] == 0) {
					cout << -1 << "\n";
					return 0;
				}
				if (result < tomato[i][j])
					result = tomato[i][j];
			}
		}
		cout << result - 1 << "\n"; // 처음 시작이 1 이므로 빼줘야함
	}

	return 0;
}