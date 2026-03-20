/*
도시 분할 계획
마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져 있다. 길은 어느 방향으로든지 다닐 수 있는 편리한 길이다. 
그리고 각 길마다 길을 유지하는데 드는 유지비가 있다. 
임의의 두 집 사이에 경로가 항상 존재한다
마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다. 
마을이 너무 커서 혼자서는 관리할 수 없기 때문이다

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
    int maxCost = 0;

    // {가중치, 정점}
    pq.push({0, 1});

    int result = 0;

    while(!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if(visited[now]) continue;

        visited[now] = true;
        result += cost;
        maxCost = max(maxCost,cost);

        for(auto [next, weight] : graph[now]) {
            if(!visited[next]) {
                pq.push({weight, next});
            }
        }
    }

    result -= maxCost;
    cout << result << '\n';

    return 0;
}