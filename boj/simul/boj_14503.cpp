/*
로봇 청소기
1.현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
  바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
  바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
  반시계 방향으로 90도 회전한다.
  바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
  1번으로 돌아간다.
*/

#include<iostream>

using namespace std;

int room[50][50];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n,m;
    int r,c,d;
    int cnt = 0;

    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++)
        for(int j=0;j<m; j++)
            cin >> room[i][j];
    

    while (true)
    {
        int flag = 0;

        if(room[r][c] == 0){
            room[r][c] = 2;
            cnt++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(room[nx][ny] == 0)
                    flag = 1;        
            }
        }

        if(flag){
            d = (d+3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(room[nx][ny] == 0){
                    r = nx;
                    c = ny;
                }
            }
        }
        else{
            int tmp = (d+2) %2;
            int nx = r + dx[tmp];
            int ny = c + dy[tmp];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(room[nx][ny] == 1){
                    break;
                }
                else{
                    r = nx;
                    c = ny;
                }
            }
        }
    }
    
    cout << cnt;
}