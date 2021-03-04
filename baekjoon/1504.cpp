// 특정한 최단 경로

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321
#define MAX 801

int path[MAX];
vector<pair<int, int>> vertex[MAX]; // connected vertex, cost (vertex의 인덱스는 1~800 사용)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q; // cost, index, cost로 오름차순(맨앞은 최솟값)

void bfs(int start) {
	q.push(make_pair(0, start)); // 시작지점
	path[start] = 0;

	while (!q.empty()) {
		int start = q.top().second;
		int start_cost = q.top().first;
		q.pop();

		// start와 연결된 모든 vertex에 대해서 거리 업데이트
		for (int i = 0; i < vertex[start].size(); i++) {
			int next = vertex[start][i].first;
			int next_cost = vertex[start][i].second;
			int new_cost = start_cost + next_cost;

			if (path[next] > new_cost) {
				path[next] = new_cost;
				q.push(make_pair(new_cost, next));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 1 -> ... -> v1 -> ... -> v2 -> ... -> N
	// 1 -> ... -> v2 -> ... -> v1 -> ... -> N
	// 1부터 v1,v2까지의 최소경로, v1부터 v2까지의 최소경로(양방향이므로 v2->v1도 거리 같음), v2부터 N까지의 최소경로, v1부터 N까지의 최소경로 => 즉 4번의 다익스트라 진행

	int N, E, v1, v2;
	cin >> N >> E; // N : 정점개수, E : 간선개수

	if (E == 0) {
		// 간선이 하나도 없는 경우에는 무조건 불가능 !!!!!!!!!!!중요!!!!!!!!!!!!!!!
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c; 
		// a와 b 사이의 양방향 간선 존재, 가중치 c (c는 양수)

		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2; 
	// 반드시 거쳐야 하는 두개의 서로 다른 정점

	int v1_v2, v2_v1, v1_N, v2_N, result;
	int flag = 0; 
	// 1 : 1->v1->v2->N 가능, 2 : 1->v2->v1->N 가능, 3 : 둘다 가능, 0 : 둘다 불가능

	for (int i = 0; i < MAX; i++)
		path[i] = INF;
	bfs(1);

	v1_v2 = path[v1];
	// 1부터 v1
	v2_v1 = path[v2];
	// 1부터 v2

	if (v1_v2 == INF && v2_v1 != INF) flag = 2;
	else if (v1_v2 != INF && v2_v1 == INF) flag = 1;
	else if (v1_v2 != INF && v2_v1 != INF) flag = 3;

	if (flag == 1 || flag == 3) {
		for (int i = 0; i < MAX; i++)
			path[i] = INF;
		bfs(v1);

		v1_v2 += path[v2];
		// 1부터 v1을 거친 v2
		v1_N = path[N];
		// v1부터 N
	}

	if (flag == 2 || flag == 3) {
		for (int i = 0; i < MAX; i++)
			path[i] = INF;
		bfs(v2);

		v2_v1 += path[v1];
		// 1부터 v2를 거친 v1
		v2_N = path[N];
		// v2부터 N
	}
	
	if (flag == 0) {
		result = -1;
	}
	else if (flag == 1) { 
		v1_v2 += v2_N;
		result = v1_v2;
	}
	else if (flag == 2) { 
		v2_v1 += v1_N;
		result = v2_v1;
	}
	else if (flag == 3) {
		v1_v2 += v2_N;
		v2_v1 += v1_N;

		if (v1_v2 <= v2_v1)
			result = v1_v2;
		else
			result = v2_v1;
	}
	cout << result << "\n";

	return 0;
}