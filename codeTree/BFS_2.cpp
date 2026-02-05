/*
k번 최댓값으로 이동하기
*/

#include <iostream>
#include <queue>


using namespace std;

int n, k;
int grid[100][100];
int r, c;

bool visited[100][100];

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};

bool whichhi(int val, int x, int y, int cV, int cX, int cY){
    if (val > cV){
        return true;
    }
    else if(val == cV){
        if (x < cX){
           return true;
        }
        else if(x == cX){
            if(y < cY){
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    cin >> r >> c;
    r -= 1;
    c -= 1;

    // Please write your code here.
    int highest = grid[r][c];

    queue<int> px;
    queue<int> py;

    int currentHi = -1;
    int currentX = r;
    int currentY = c;

    for(int i = 0; i < k; i++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        px.push(currentX);
        py.push(currentY);
        currentHi = -1;

        while(!px.empty()){
            int x = px.front(); px.pop();
            int y = py.front(); py.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (!visited[nx][ny] && grid[nx][ny] < highest) {
                        visited[nx][ny] = true;
                        px.push(nx);
                        py.push(ny);
                        
                        if( whichhi(grid[nx][ny], nx, ny, currentHi, currentX, currentY)){
                            currentHi = grid[nx][ny];
                            currentX = nx;
                            currentY = ny;
                        }
                    }
                }
            }
            
        }
        highest = currentHi;
    }

    cout << currentX+1 << " " << currentY+1 ;
    return 0;
}
