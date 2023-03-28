/* Dijkstra algorithm, 다익스트라 알고리즘
 * 최단 경로를 구하는 알고리즘
 * 음의 간선이 없을 때 사용
 */
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define INF 1e9
#define MAX_SIZE 10001

using namespace std;

vector<pair<int, int> > graph[MAX_SIZE]; //pair {to, cost}	
int d[MAX_SIZE]; // 최단거리 저장

void djikstra(int start) {
	priority_queue<pair<int, int> > pq; //pair {최단경로, 목적지}
	d[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue; // 이미 방문한 노드는 건너뛰기

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}
