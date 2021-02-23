// �� �μ��� �̵��ϱ�

#include<iostream>
#include<queue>
using namespace std;

#define MAX 1001

// ���� �ѹ� ���� �� �ִٴ� ������ �ʿ�
struct block {
	int x, y, chance;
};

int N, M;
char map[MAX][MAX];
bool isVisited[MAX][MAX][2];
int block_count[MAX][MAX][2];
// ���� ���� �ʰ� �̵��ϴ� �����
// ���� ���� �� �̵��ϴ� ����� ����

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y,int chance) {
	queue<block> q;
	block temp;
	temp.x = x;
	temp.y = y;
	temp.chance = chance; // ó�� ������ �� ���� ��ȸ �ѹ� ������ ����

	q.push(temp);
	block_count[x][y][0] = 1; // ��������(���� ���� ���� ���¿��� ����)
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
				// �׳� �� �� �ִ� ���� ���(���� ��ȸ ���� 1�� ���� ���)
				if (map[nx][ny] == '0' && isVisited[nx][ny][0] == false && chance == 1) {
					q.push({ nx,ny,1 });

					block_count[nx][ny][0] = block_count[x][y][0] + 1;
					isVisited[nx][ny][0] = true;
				}

				// �׳� �� �� �ִ� ���� ���(���� ��ȸ�� ���� ���)
				else if (map[nx][ny] == '0' && isVisited[nx][ny][1] == false && chance == 0) {
					q.push({ nx,ny,0 });

					block_count[nx][ny][1] = block_count[x][y][1] + 1;
					isVisited[nx][ny][1] = true;
				}

				// ���� �ִ� �κ������� ���� �� �ִ� ��ȸ�� �ѹ� ���� ��
				else if (map[nx][ny] == '1' && isVisited[nx][ny][1] == false && chance == 1) {
					q.push({ nx,ny,0 });

					block_count[nx][ny][1] = block_count[x][y][0] + 1;
					isVisited[nx][ny][1] = true;
				}
				// ���� �ִ� �κ��̸鼭 ���� �� ���� ���� ���� ����

				// ����׽�Ʈ��
				/*cout << "\n========== �� �ȶհ� �̵����� �� =======\n";
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << block_count[i][j][0] << " ";
					}
					cout << "\n";
				}
				cout << "\n";

				cout << "\n========== �� �հ� �̵����� �� =======\n";
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