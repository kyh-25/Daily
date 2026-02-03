/*
정수 사각형 최솟값의 최대
N×N 행렬이 주어졌을 때, (1, 1)에서 시작하여 오른쪽 혹은 밑으로만 이동하여 (N, N)으로 간다고 했을 때 
거쳐간 위치에 적혀있는 숫자들 중 최솟값을 최대로 하는 프로그램을 작성해보세요.
*/

#include <iostream>

using namespace std;

int n;
int grid[100][100];

int dp[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    //초기화
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(grid[0][i],dp[0][i-1]);
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(grid[i][0],dp[i-1][0]);
    }
    //점화
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(grid[i][j], max(dp[i-1][j],dp[i][j-1]));
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}
