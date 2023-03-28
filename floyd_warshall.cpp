/* Floyd-Warshall Algorithm, 플루이드-워셜 알고리즘
 * 최단 경로 알고리즘
 * 모든 지점에서 다른 모든 지점까지의 최단경로를 구한다
 * 다이나믹 프로그래밍, $Dab = min(Dak, Dab + Dkb)$
 */

#include <iostream>

#define INF 100000

using namespace std;

// i번 노드에서 j번 노드로 가는 비용
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

int main() {
	for (int k = 0; k < 4; k++) { //거쳐가는 정점
		for (int i = 0; i < 4; i++) { // 출발 정점
			for (int j = 0; j < 4; j++) { // 도착 정점
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}	
}
