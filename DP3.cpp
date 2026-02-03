/*
    최대 증가 부분 수열 LIS
*/
#include <iostream>

using namespace std;

int N;
int M[1000];
int dp[1000];
int Max;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (M[j] < M[i]) {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
    }

    Max = 0;
    for (int i = 0; i < N; i++) {
       if(Max < dp[i])
            Max = dp[i];
    }

    cout << Max;

    return 0;
}
