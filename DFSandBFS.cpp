#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void bfs(int start, int len, int* graph){ // 큐 구현 너비
    int flag[len+1] = {0}; //탐색 했는지
    queue<int> waiting; //탐색 대기열
    int current; //현재 정점

    waiting.push(start); //초기 정점
    do
    {
        if (flag[waiting.front()] == 0) //탐색 하지 않은 거만 꺼냄
        {
            flag[waiting.front()] = 1; //탐색함 표시

            current = waiting.front(); //탐색
            waiting.pop();   
            cout << current << " ";
            
            //대기열 채우기
           for (int i = 1; i <= len; i++)
            {
                if (graph[current*(len+1)+i] == 1) //링크되어 있는 정점
                {
                    if (flag[i] == 0) //탐색한적 없으면
                    {
                        waiting.push(i);
                    }  
                }  
            }
        }
        else //이미 탐색 완료
        {
            waiting.pop();
        }
    } while (!waiting.empty());
    cout << endl;
}

void dfs(int start, int len, int* graph){ // 스택 구현 깊이
    int flag[len+1] = {0}; //탐색 했는지
    stack<int> waiting; //탐색 대기열
    int current; //현재 정점

    waiting.push(start); //초기 정점
    do
    {
        if (flag[waiting.top()] == 0) //탐색 하지 않은 거만 꺼냄
        {
            flag[waiting.top()] = 1; //탐색함 표시

            current = waiting.top(); //탐색
            waiting.pop();   
            cout << current << " ";
            
           //대기열 채우기
           for (int i = len; i >= 1; i--)
            {
                if (graph[current*(len+1)+i] == 1)
                {
                    if (flag[i] == 0)
                    {
                        waiting.push(i);
                    }  
                }  
            }
        }
        else
        {
            waiting.pop();
        }
    } while (!waiting.empty());
    cout << endl;
}


int main() {
    int n,m; // 정점의 개수, 간선의 개수
    int v; // 시작 정점

    cin >> n >> m >> v;

    int graph[n+1][n+1] = {0};
    for (size_t i = 0; i < m; i++) // 간선 생성
    {
        int start, end;
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1;
    }
    
    // // 체크용
    // for (int i = 1; i <= n; i++) {
    //     for (int j=1; j<=n;j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << "dfs:";
    dfs(v,n,*graph);
    //cout << "bfs:";
    bfs(v,n,*graph);

    return 0;
}
 