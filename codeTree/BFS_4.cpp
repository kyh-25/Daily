/*
비 피하기
숫자 0, 1, 2, 3로만 이루어진 N×N격자에서 사람이 H명 겹치지 않게 서 있고, 
비를 피할 수 있는 공간의 위치 M개가 주어졌을 때 각 사람마다 비를 피할 수 있는 가장 가까운 공간까지의 거리를 구하는 프로그램을 작성해보세요. 
숫자 0은 해당 칸이 이동할 수 있는 곳임을, 숫자 1은 벽이 있어 해당 칸이 이동할 수 없는 곳임을 의미합니다. 
숫자 2는 해당 칸에 사람이 서있음을 의미하고, 숫자 3은 해당 공간이 비를 피할 수 있는 공간임을 의미합니다. 
사람은 상하좌우 인접한 곳으로만 움직 일 수 있으며 한 칸 움직이는 데 정확히 1초가 소요됩니다. 벽이 아닌 곳은 전부 이동이 가능합니다.
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, h, m;
int grid[100][100];

int cnt[100][100];

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
        
    queue<pair<int,int>> q;
    int x,y;

    // 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i][j] = -1;
            if (grid[i][j] == 3) {
                cnt[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second; 
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (cnt[nx][ny] == -1 && grid[nx][ny] != 1) {
                    cnt[nx][ny] = cnt[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) 
                cout << cnt[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
