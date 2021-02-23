// 벽 부수고 이동하기

#include<iostream>
#include<queue>
using namespace std;

#define MAX 1001

// 블럭을 한번 뚫을 수 있다는 변수도 필요
struct block {
	int x, y, chance;
};

int N, M;
char map[MAX][MAX];
bool isVisited[MAX][MAX][2];
int block_count[MAX][MAX][2];
// 벽을 뚫지 않고 이동하는 모습과
// 벽을 뚫은 후 이동하는 모습을 나눔

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y,int chance) {
	queue<block> q;
	block temp;
	temp.x = x;
	temp.y = y;
	temp.chance = chance; // 처음 시작할 때 뚫을 기회 한번 가지고 시작

	q.push(temp);
	block_count[x][y][0] = 1; // 시작지점(벽을 뚫지 않은 상태에서 시작)
	isVisited[x][y][0] = true;
	isVisited[x][y][1] = true;

	while (!q.empty()) {
		block block_front = q.front();
		x = block_front.x;
		y = block_front.y;
		chance = block_front.chance;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < MAX && 0 <= ny && ny < MAX) {
				// 그냥 갈 수 있는 길인 경우(뚫을 기회 아직 1번 남은 경우)
				if (map[nx][ny] == '0' && isVisited[nx][ny][0] == false && chance == 1) {
					q.push({ nx,ny,1 });

					block_count[nx][ny][0] = block_count[x][y][0] + 1;
					isVisited[nx][ny][0] = true;
				}

				// 그냥 갈 수 있는 길인 경우(뚫을 기회는 없는 경우)
				else if (map[nx][ny] == '0' && isVisited[nx][ny][1] == false && chance == 0) {
					q.push({ nx,ny,0 });

					block_count[nx][ny][1] = block_count[x][y][1] + 1;
					isVisited[nx][ny][1] = true;
				}

				// 막혀 있는 부분이지만 뚫을 수 있는 기회가 한번 있을 때
				else if (map[nx][ny] == '1' && isVisited[nx][ny][1] == false && chance == 1) {
					q.push({ nx,ny,0 });

					block_count[nx][ny][1] = block_count[x][y][0] + 1;
					isVisited[nx][ny][1] = true;
				}
				// 막혀 있는 부분이면서 뚫을 수 없는 경우는 가지 않음

				// 출력테스트용
				/*cout << "\n========== 벽 안뚫고 이동했을 때 =======\n";
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << block_count[i][j][0] << " ";
					}
					cout << "\n";
				}
				cout << "\n";

				cout << "\n========== 벽 뚫고 이동했을 때 =======\n";
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << block_count[i][j][1] << " ";
					}
					cout << "\n";
				}
				cout << "\n";*/
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	bfs(0, 0, 1);

	if (block_count[N - 1][M - 1][0] == 0 && block_count[N - 1][M - 1][1] == 0)
		cout << -1 << "\n";
	else if (block_count[N - 1][M - 1][0] == 0)
		cout << block_count[N - 1][M - 1][1] << "\n";
	else if (block_count[N - 1][M - 1][1] == 0)
		cout << block_count[N - 1][M - 1][0] << "\n";
	else {
		if (block_count[N - 1][M - 1][0] < block_count[N - 1][M - 1][1])
			cout << block_count[N - 1][M - 1][0] << "\n";
		else
			cout << block_count[N - 1][M - 1][1] << "\n";
	}

	return 0;
}