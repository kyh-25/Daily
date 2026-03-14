/*
 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;
const int INF = INT_MAX / 2;

vector<int> dijkstra(int start, int n, vector<vector<pii>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (cost > dist[u]) continue;

        for (auto [w, v] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<vector<pii>> graph(n + 1);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 양방향 간선
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 세 시작점에서 각각 다익스트라 실행
    vector<int> d1  = dijkstra(1,  n, graph);
    vector<int> dv1 = dijkstra(v1, n, graph);
    vector<int> dv2 = dijkstra(v2, n, graph);

    // 경로 1: 1 -> v1 -> v2 -> N
    long long path1 = (long long)d1[v1] + dv1[v2] + dv2[n];

    // 경로 2: 1 -> v2 -> v1 -> N
    long long path2 = (long long)d1[v2] + dv2[v1] + dv1[n];

    long long ans = min(path1, path2);

    if (ans >= INF) cout << -1 << "\n";
    else            cout << ans << "\n";

    return 0;
}