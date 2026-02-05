/*
    상하좌우 미로 탐색
    최단거리 구하기
*/

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int grid[100][100];
int cnt[100][100];

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[i][j] = -1;
        }
    }

    queue<int> queueX;
    queue<int> queueY;
    queueX.push(0);
    queueY.push(0);

    cnt[0][0] = 0;
    cnt[n-1][m-1] = -1;

    while(!queueX.empty()){
        int x = queueX.front(); queueX.pop();
        int y = queueY.front(); queueY.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (cnt[nx][ny] == -1 && grid[nx][ny] == 1) {
                    cnt[nx][ny] = cnt[x][y] + 1;
                    queueX.push(nx);
                    queueY.push(ny);
                }
            }
        }
    }

    cout<< cnt[n-1][m-1];
    return 0;
}

