// boj 1753 최단경로 - 가중치 그래프, 다익스트라 알고리즘
/*
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.
단, 모든 간선의 가중치는 10 이하의 자연수이다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E, start; //노드 수, 간선 수, 시작노드

    //입력
    cin >> V >> E >> start;
    vector<pair<int,int>>* graph = new vector<pair<int,int>>[V+1]; // (도착, 가중치)
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }

    vector<int> dist(V+1, INF); //시작노드에서 각 노드까지 거리
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //노드(거리, 정점)
    pq.push({0,start});

    //최단거리 계산
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;

        for(auto &[v,w] : graph[u]){ //graph(현노드) : 현재노드에서 다음으로 갈수있는 것들
            if(dist[v] > d + w){ //갱신
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    //출력
    for(int i=1;i<=V;i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
