/*
나이트
*/

#include <iostream>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;

int dx[8] = {-2, -1, 2, 1, -2, -1,  2,  1}; 
int dy[8] = { 1,  2, 1, 2, -1, -2, -1, -2};

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.
    int cnt[100][100];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cnt[i][j] = -1;
    
    queue<int> qX;
    queue<int> qY;
    
    qX.push(r1);
    qY.push(c1);
    cnt[r1][c1] = 0;

    if(r1==r2 && c1==c2)
    {
        cout << "0";
        return 0;
    }

    while (!qX.empty())
    {
        int x = qX.front(); qX.pop();
        int y = qY.front(); qY.pop();

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (cnt[nx][ny] == -1 || cnt[nx][ny] > cnt[x][y] + 1) {
                    cnt[nx][ny] = cnt[x][y] + 1;
                    qX.push(nx);
                    qY.push(ny);

                    if (nx== r2 && ny == c2)
                    {
                        cout << cnt[r2][c2];
                        return 0;
                    }
                    
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout << cnt[i][j] << " ";
            cout << endl;
        }
        cout << "------------------------------";
    }
    
    cout << "-1";
    return 0;
}
