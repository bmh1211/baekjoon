// 연구소

#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

queue<pair<int, int>> q;
int result = 0;
int virus_origin[8][8];
int virus[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;

void bfs() {
	// 박테리아 퍼지는 함수
	// 0은 빈칸, 1은 벽, 2는 바이러스

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && virus[nx][ny] == 0) {
				virus[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	// 다 돌고 난 후 안전지대 개수 확인
	int safezone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 0)
				safezone++;
		}
	}
	if (result < safezone)
		result = safezone;
}

void three_wall() {
	// 벽을 3개 만들어야 함
	// 벽을 세웠다가 하위 포문을 전부 돌면 그 자리의 벽을 없애주고 다음자리의 벽을 만들어야함

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 0) {
				// 벽 하나 세워짐
				virus[i][j] = 1;
				virus_origin[i][j] = 1;
				
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						if (virus[k][l] == 0) {
							// 벽 두개 세워짐
							virus[k][l] = 1;
							virus_origin[k][l] = 1;

							for (int m = 0; m < N; m++) {
								for (int n = 0; n < M; n++) {
									if (virus[m][n] == 0) {
										// 벽 세개 세워짐
										virus[m][n] = 1;
										virus_origin[m][n] = 1;

										bfs();

										// 다음 벽세우기에 지장이 가지 않도록 벽을 제거해줌
										virus_origin[m][n] = 0;
										memcpy(virus, virus_origin, sizeof(virus_origin));
									}
								}
							}
							// 다음 벽세우기에 지장이 가지 않도록 벽을 제거해줌
							virus_origin[k][l] = 0;
							memcpy(virus, virus_origin, sizeof(virus_origin));
						}
					}
				}
				// 다음 벽세우기에 지장이 가지 않도록 벽을 제거해줌
				virus_origin[i][j] = 0;
				memcpy(virus, virus_origin, sizeof(virus_origin));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 바이러스가 퍼지는 것은 BFS로 가능
	// 벽을 3개를 만들어야지

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> virus[i][j];
		}
	}
	
	// 계속 변형되는 virus를 원복시켜줄 virus_origin
	memcpy(virus_origin, virus, sizeof(virus));

	three_wall();

	cout << result << "\n";

	return 0;
}