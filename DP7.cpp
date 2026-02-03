/*
계단 오르기
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int coin[1001];
int dp[1001][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    // 초기화
    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= 3; k++)
            dp[i][k] = -1e9;

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= 3; k++) {
            // 2칸 이동
            if (i >= 2 && dp[i - 2][k] >= 0) {
                dp[i][k] = max(dp[i][k], dp[i - 2][k] + coin[i]);
            }
            // 1칸 이동
            if (k >= 1 && dp[i - 1][k - 1] >= 0) {
                dp[i][k] = max(dp[i][k], dp[i - 1][k - 1] + coin[i]);
            }
        }
    }

    int ans = 0;
    for (int k = 0; k <= 3; k++) {
        ans = max(ans, dp[n][k]);
    }

    cout << ans << endl;
    return 0;
}
