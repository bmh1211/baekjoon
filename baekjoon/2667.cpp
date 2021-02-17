// 단지번호붙이기

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

char map[26][26];
bool isVisited[26][26];
vector<int> home_count;

void bfs(int start_x, int start_y) {
	int count = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	isVisited[start_x][start_y] = true;
	count++;

	while (!q.empty()) {
		start_x = q.front().first;
		start_y = q.front().second;
		q.pop();

		if (start_x < 25 && map[start_x + 1][start_y] == '1' && isVisited[start_x + 1][start_y] == false) {
			q.push(make_pair(start_x + 1, start_y));
			isVisited[start_x + 1][start_y] = true;
			count++;
		}
		if (start_x > 0 && map[start_x - 1][start_y] == '1' && isVisited[start_x - 1][start_y] == false) {
			q.push(make_pair(start_x - 1, start_y));
			isVisited[start_x - 1][start_y] = true;
			count++;
		}
		if (start_y < 25 && map[start_x][start_y + 1] == '1' && isVisited[start_x][start_y + 1] == false) {
			q.push(make_pair(start_x, start_y + 1));
			isVisited[start_x][start_y + 1] = true;
			count++;
		}
		if (start_y > 0 && map[start_x][start_y - 1] == '1' && isVisited[start_x][start_y - 1] == false) {
			q.push(make_pair(start_x, start_y - 1));
			isVisited[start_x][start_y - 1] = true;
			count++;
		}
	}

	home_count.push_back(count);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N,group_count=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && isVisited[i][j] == false) {
				bfs(i, j);
				group_count++;
			}
		}
	}
	sort(home_count.begin(), home_count.end(), less<int>());

	cout << group_count << "\n";
	for (int i = 0; i < home_count.size(); i++) {
		cout << home_count[i] << "\n";
	}

	return 0;
}