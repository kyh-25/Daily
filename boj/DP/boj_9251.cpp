/*
LCS
최장 공통 부분 수열

같으면 1증가
다르면 A-1 열과 B-1 열 비교해서 선택

*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int dp[1001][1001] = {0};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m];
    
    return 0;
}