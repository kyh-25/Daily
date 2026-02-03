/*
    상하좌우 미로 탐색
*/

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];

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
            visited[i][j] = 0;
        }
    }

    queue<int> stackX;
    queue<int> stackY;
    stackX.push(0);
    stackY.push(0);

    visited[0][0] = 1;

    while(!stackX.empty()){
        int x = stackX.front(); stackX.pop();
        int y = stackY.front(); stackY.pop();

        if (x == n - 1 && y == m - 1) {
            cout << 1;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    stackX.push(nx);
                    stackY.push(ny);
                }
            }
        }
    }

    cout<< 0;
    return 0;
}

