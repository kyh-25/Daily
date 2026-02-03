//boj 7576 토마토 - BFS, 최단길이 구하기
/*
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

#include <iostream>
#include <queue>
using namespace std;

const int maxM = 1000;
const int maxN = 1000;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    int m,n; //가로, 세로
    int total = 0; //총 토마토 개수
    int cnt = 0; //현 익은 토마토 개수
    int day = 0; //걸린 시간
    int arr[maxM][maxN]; //토마토판
    int visited[maxM][maxN];
    queue<pair<int,int>> next; //대기열
    queue<pair<int,int>> current; 

    //입력
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {    
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            visited[i][j] = 0;
            //토마토 있는 경우
            if(arr[i][j] != -1) total++;
            if(arr[i][j] == 1) {
                cnt++;
                current.push({i,j});
                visited[i][j] = 1;
            } 
        }
    }
    
    //BFS 탐색
    while (!current.empty())
    {                     
        if (cnt==total)
            break;
   
        while (!current.empty())
        {
            auto [x,y] = current.front(); current.pop();
            for(int d=0; d<4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue; //예외처리
                if (arr[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    arr[nx][ny] = 1;
                    next.push({nx,ny});
                    cnt++;
                }
            }
        }
        
        swap(current,next);
        while (!next.empty()) next.pop();
        if (!current.empty()) day++;
    }
    
    //출력
    if (cnt == total) 
        cout << day;
    else
        cout << "-1";
    
    return 0;
}