/*
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, 
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int maze[100][100];
int cnt[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string line;
        cin >> line; // 한 줄을 통째로 입력받음
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - '0'; // 문자를 숫자로 변환 ('1' -> 1)
        }    
    }

    queue<int> qx;
    queue<int> qy;
    qx.push(0);
    qy.push(0);
    cnt[0][0] = 1;

    while (!qx.empty())
    {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]==1 && cnt[nx][ny] == 0){
                qx.push(nx);
                qy.push(ny);
                cnt[nx][ny] = cnt[x][y] + 1;

                if(nx == n-1 && ny == m-1)
                    break;
            }
        }
    }
    
    cout << cnt[n-1][m-1];
}  