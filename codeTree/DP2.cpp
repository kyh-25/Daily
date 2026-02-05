/*
    사각 디그리 
    최대 거리
*/

#include <iostream>

using namespace std;

int n;
int grid[100][100];
int cnt[100][100];

int dx[2] = {1, 0}; 
int dy[2] = {0, 1};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cnt[i][j] = 0;
        }
    }

    // Please write your code here.
    cnt[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 2; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(cnt[nx][ny] < cnt[i][j] + grid[nx][ny])
                    cnt[nx][ny] = cnt[i][j] + grid[nx][ny];
            }
            }
        }
    }

    cout << cnt[n-1][n-1];
    return 0;
}
