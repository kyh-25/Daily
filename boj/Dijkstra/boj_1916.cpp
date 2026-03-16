/*
최소비용 구하기

N개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라.  => 단방향 그래프
도시의 번호는 1부터 N까지이다.
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

    int n,m;
    vector<vector<pii>> graph(1001);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back({w,b});
        //graph[b].push_back({w,a});
    }

    int start, end;
    cin >> start >> end;
    vector<int> dist = dijkstra(start,n,graph);
    cout << dist[end];

    return 0;
}