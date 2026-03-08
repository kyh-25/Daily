/*
토마토
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

#include<iostream>
#include <algorithm>
#include<queue>
#include<tuple>

using namespace std;

int tomato[100][100][100];
int day[100][100][100];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    int n,m,h;

    //입력
    cin >> m >> n >> h;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> tomato[i][j][k];
            }
        }
    }

    //초기
    queue<tuple<int,int,int>> next;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<h; k++){
                if(tomato[i][j][k]==1)
                    next.push({i,j,k});
            }
        }
    }
    //BFS
    while(!next.empty()){
        auto [x,y,z] = next.front(); next.pop();
        for(int i=0; i<6; i++){                        
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && nz>=0 && nz<h){
                if(tomato[nx][ny][nz]==0){
                    tomato[nx][ny][nz] = 1;
                    day[nx][ny][nz] = day[x][y][z]+1;                    
                    next.push({nx,ny,nz});
                }
            }
        }
    }
    //답 탐색
    int maxD = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<h; k++){
                if(tomato[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
                maxD = max(maxD, day[i][j][k]);
            }
        }
    }
    cout << maxD;
}