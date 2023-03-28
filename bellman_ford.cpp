/* Bellman-Ford Algorithm, 벨만-포드 알고리즘
 * 최단 거리를 구하는 알고리즘
 * 간선의 가중치가 음수일떄도 사용 가능
 * 매번 모든 간선을 확인
 * 느리다. O(VE)
 * 이 알고리즘을 두 번 수행하여 최단거리가 바뀌면 음수 간선 순환이있는것
 * bj 11657
 */

#include <iostream>
#include <vector>

#define MAX_SIZE 100001
#define INF 1e9

using namespace std;

struct Edge {
	int from, to, cost;
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {};
};

vector<Edge> edges;
int N; //Node 개수
int dist[MAX_SIZE]; //INF로 초기화할것

void Bellman_Ford() {
	dist[1] = 0; //시작지점		
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].from;
			int to = edges[j].to;
			int cost = edges[j].cost;

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}
	// 최단거리 구하기 완료
	// 이 아래는 한번 더 수행하여 음의 간선 확인하는 작업
	for (int i = 0; i < edges.size(); i++) {
		int from = edges[i].from;
		int to = edges[i].to;
		int cost = edges[i].cost;

		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout <<  "음의 사이클이 존재하는 그래프입니다." << endl;
		} else {
			cout << "음의 사이클이 존재하지 않는 그래프입니다." << endl;
		}
	}
}
