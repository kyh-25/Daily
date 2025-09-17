// 12865. 평범한 배낭 - 다이나믹 프로그래밍
/*
준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 
각 물건은 무게 W와 가치 V를 가지는데, 
해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 
아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 
준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.
*/

#include<iostream>
using namespace std;

int main() {
    int n, k; // n: 물건의 수, k: 버틸 수 있는 무게
    cin >> n >> k;

    int* w = new int[n];
    int* v = new int[n];
    int dp[100][100001]; // dp[i][j]: i번째 물건까지 고려했을 때, j 무게일 때의 최대 가치
    // // 2차원 배열 동적 할당
    // int** dp = new int*[n];
    // for (int i = 0; i < k; i++) {
    //     dp[i] = new int[n];
    // }

    // 입력 받기
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    
    // 다이나믹 프로그래밍
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i == 0) {
                if (j < w[i]) dp[i][j] = 0;
                else dp[i][j] = v[i];
            }
            else {
                if (j < w[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n - 1][k] << '\n';

    // 동적 할당 해제
    delete[] w;
    delete[] v;
    // for (int i = 0; i < k; i++) {
    //     delete[] dp[i];
    // }
    // delete[] dp;

    return 0;
}