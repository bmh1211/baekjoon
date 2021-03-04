// 최단경로

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 20001
#define INF 987654321

int path[MAX]; // 해당 인덱스까지 가는 최소거리
vector<pair<int, int>> vertex[MAX]; // int : 연결된 다음 정점, int : 그때의 가중치
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q; // 현재 정점에서 가장 가까운 정점을 찾도록 내림차순 정렬
											  // int : 해당 점까지의 최소 거리,  int : 그 정점의 인덱스

void bfs(int start) {
	q.push(make_pair(0, start)); // 처음 시작점(거리 : 0, 시작점 : start), 값이 INF에서 0으로 바뀌였으므로 재탐색 안함
	path[start] = 0;

	while (!q.empty()) {
		int value = q.top().first;
		int start = q.top().second;
		q.pop();
		
		for (int i = 0; i < vertex[start].size(); i++) {
			int next = vertex[start][i].first; // start와 연결된 점
			int distance = vertex[start][i].second; // start와 next 사이의 가중치

			if (path[next] > value + distance) {
				// 원래 있던 next까지의 거리가 새로 체크할 거리보다 크다면 업데이트(반복진행하여 최소값으로 업데이트)
				path[next] = value + distance;
				q.push(make_pair(path[next], next)); // 체크할 다음 점 추가
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int V, E, K; // V : 정점개수, E : 간선개수, K : 시작정점
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w; // 정점 u에서 v로 가는 가중치 w인 간선
		cin >> u >> v >> w;

		vertex[u].push_back(make_pair(v, w)); // i번 정점에 연결된 모든 정점과 그 정점으로 가는 거리
	}
	
	for (int i = 0; i < MAX; i++)
		path[i] = INF; // 무한대로 초기화
	
	bfs(K);
	for (int i = 1; i <= V; i++) {
		if (path[i] == INF)
			cout << "INF" << "\n";
		else
			cout << path[i] << "\n";
	}

	return 0;
}