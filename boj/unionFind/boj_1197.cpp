/*
최소 스패닝 트리
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 
주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> graph;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin >> v >> e;

    graph.resize(v+1);
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<bool> visited(v+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    // {가중치, 정점}
    pq.push({0, 1});

    int result = 0;

    while(!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if(visited[now]) continue;

        visited[now] = true;
        result += cost;

        for(auto [next, weight] : graph[now]) {
            if(!visited[next]) {
                pq.push({weight, next});
            }
        }
    }

    cout << result << '\n';

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> parent;

// Find (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Union
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    edges.resize(e);

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 부모 초기화
    parent.resize(v + 1);
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // 가중치 기준 정렬
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    int result = 0;

    for (auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        // 사이클 체크
        if (find(u) != find(v)) {
            unite(u, v);
            result += w;
        }
    }

    cout << result << '\n';

    return 0;
}
*/