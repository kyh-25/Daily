/*
    아래, 오른쪽 미로 탐색
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];

int dx[2] = {1, 0}; 
int dy[2] = {0, 1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    vector<int> stackX;
    vector<int> stackY;
    stackX.push_back(0);
    stackY.push_back(0);

    visited[0][0] = 1;

    while(!stackX.empty()){
        int x = stackX.back(); stackX.pop_back();
        int y = stackY.back(); stackY.pop_back();

        if (x == n - 1 && y == m - 1) {
            cout << 1;
            return 0;
        }

        for (int d = 0; d < 2; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    stackX.push_back(nx);
                    stackY.push_back(ny);
                }
            }
        }
    }

    cout<< 0;
    return 0;
}

