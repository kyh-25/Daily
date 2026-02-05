/*
적절한 옷 고르기 
2차원 배열 모델링
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MINV = -1e9;

int N, M;
int s[200], e[200], v[200];
int dp[201][201];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }
    
    // Please write your code here.

    //초기화
    for (int day = 1; day <= M; day++)
        for (int i = 0; i < N; i++)
            dp[day][i] = MINV;

    // 1일차 초기화
    for (int i = 0; i < N; i++) {
        if (s[i] <= 1 && 1 <= e[i]) {
            dp[1][i] = 0;
        }
    }

    for (int day = 2; day <= M; day++) {
        for (int i = 0; i < N; i++) {
            if (!(s[i] <= day && day <= e[i])) continue;

            for (int j = 0; j < N; j++) {
                if (dp[day - 1][j] == MINV) continue;
                if (!(s[j] <= day - 1 && day - 1 <= e[j])) continue;

                dp[day][i] = max(
                    dp[day][i],
                    dp[day - 1][j] + abs(v[i] - v[j])
                );
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[M][i]);
    }

    cout << ans << endl;
    return 0;
}
