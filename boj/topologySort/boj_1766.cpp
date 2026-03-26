/*
문제집
N개의 문제는 모두 풀어야 한다.
먼저 푸는 것이 좋은 문제가 있는 문제는, 
먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
가능하면 쉬운 문제부터 풀어야 한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }

    priority_queue<int,vector<int>,greater<int>> q;
    // indegree 0인 노드 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    //위상정렬
    //vector<int> result;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        cout << cur << " ";
        //result.push_back(cur);

        for (int next : graph[cur]) {
            degree[next]--;
            if (degree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 사이클 체크
    // if (result.size() != n) {
    //     cout << "Cycle exists! Topological sort not possible\n";
    // }
 
    // 출력
    // for (int x : result) {
    //     cout << x << " ";
    // }

    return 0;
}