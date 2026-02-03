/*
    갈 수 있는 곳들
*/
#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};



int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {cin >> grid[i][j]; visited[i][j] = false;}

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    // Please write your code here.
    int cnt = 0;
    for(int i = 0; i < k; i++){
        queue<int> queueX;
        queue<int> queueY;
        int cr = r[i] -1;
        int cc = c[i] -1;
        if (visited[cr][cc] == false)
        {
            visited[cr][cc] = true;
            cnt++;
            queueX.push(cr);
            queueY.push(cc);
        }
        

        while(!queueX.empty()){
            int x = queueX.front(); queueX.pop();
            int y = queueY.front(); queueY.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (!visited[nx][ny] && grid[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        cnt ++;
                        queueX.push(nx);
                        queueY.push(ny);
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
