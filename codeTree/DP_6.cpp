/*
배낭 채우기
N개의 보석의 정보가 주어졌을 때, 
보석을 적절하게 골라 무게의 합이 M을 넘지 않도록 하면서 가치의 합은 최대가 되도록 하는 프로그램을 작성해보세요.

예를 들어 N=4, M=20, 보석의 종류가 다음과 같이 주어졌다고 생각해봅시다.
*/

#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];

int dp[101][10001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    // Please write your code here.
    // 이거 틀림
    int maxValue = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i-1][j];

            if (j >= w[i-1]) {
                dp[i][j] = max(dp[i][j],
                               dp[i-1][j - w[i-1]] + v[i-1]);
                maxValue = max(maxValue, dp[i][j]);
            }
        }
    }

    // 이게 정석
    int dp[10001] = {0};

    for (int i = 1; i <= N; i++) {
        for (int weight = M; weight >= w[i]; weight--) {
            dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
        }
    }
    cout << maxValue << '\n';

    return 0;
}
