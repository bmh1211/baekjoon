// 토마토 3차원

#include<iostream>
#include<queue>
using namespace std;

struct Tomato {
	int x, y, z;
};

queue<Tomato> q;
int tomato[101][101][101];
bool isVisited[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 }; // 위 아래
int dy[6] = { 0,0,1,-1,0,0 }; // 오른쪽 왼쪽
int dz[6] = { 0,0,0,0,1,-1 }; // 앞 뒤
int tomato_total = 0;
int N, M, H;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		isVisited[x][y][z] = true;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H) {
				if (tomato[nx][ny][nz] == 0 && isVisited[nx][ny][nz] == false) {
					Tomato temp;
					temp.x = nx;
					temp.y = ny;
					temp.z = nz;

					q.push(temp);
					isVisited[nx][ny][nz] = true;
					tomato[nx][ny][nz] = tomato[x][y][z] + 1;
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
	cin >> N >> M >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tomato[i][j][k];

				if (tomato[i][j][k] == 0)
					tomato_total++;
				else if (tomato[i][j][k] == 1) {
					Tomato temp;
					temp.x = i;
					temp.y = j;
					temp.z = k;

					q.push(temp); // 익은 토마토는 queue에 넣어줌
				}
			}
		}
	}

	if (tomato_total == 0)
		cout << 0 << "\n";
	else {
		bfs();

		int result = tomato[0][0][0];
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (tomato[i][j][k] == 0) {
						cout << -1 << "\n";
						return 0;
					}
					if (result < tomato[i][j][k])
						result = tomato[i][j][k];
				}
			}
		}
		cout << result - 1 << "\n"; // 처음 시작이 1 이므로 빼줘야함
	}

	return 0;
}