/*
2차원 최대 증가 수열
N×M 크기인 직사각형의 각 칸에 수들이 하나씩 적혀있습니다. 
왼쪽 상단 (1, 1)에서 출발한다고 했을 때 특정 룰을 만족하면서 밟을 수 있는 칸의 최대 수를 구하는 프로그램을 작성해보세요.

아래는 특정 룰에 대한 설명입니다.
이동은 항상 점프를 통해서만 가능합니다. 또, 점프 진행시 항상 현재 위치에 적혀있는 수보다, 점프한 이후의 칸에 적혀있는 수가 더 커야만 합니다.
점프 진행시 현재 위치에서 적어도 한칸 이상 오른쪽에 있는 위치이며 동시에 현재 위치에서 적어도 한칸 이상 아래쪽에 있는 위치인 곳으로만 점프가 가능합니다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = -1; 
        }
    }

    // Please write your code here.
    dp[0][0] = 1; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1) continue;

            for (int ni = i + 1; ni < n; ni++) {
                for (int nj = j + 1; nj < m; nj++) {
                    if (grid[ni][nj] > grid[i][j]) {
                        dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << '\n';
    return 0;
}
