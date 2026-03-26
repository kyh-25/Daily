/*
줄 세우기 - 위상정렬
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 
각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 
마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 
일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

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

    queue<int> q;
    // indegree 0인 노드 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    //위상정렬
    //vector<int> result;
    while (!q.empty()) {
        int cur = q.front();
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