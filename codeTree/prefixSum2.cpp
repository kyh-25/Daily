/*
정수 N개의 합3
1이상 100이하의 숫자로만 이루어진 N×N 크기의 2차원 격자 상태가 주어졌을 때, 
K×K 크기의 정사각형이 격자를 벗어나지 않게 잡았을 때 정사각형 내 숫자들의 합이 최대가 되도록 하는 프로그램을 작성해보세요.
*/

#include <iostream>

using namespace std;

int n, k;
int arr[500][500];
int psum[501][501];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Please write your code here.
    // 2차원 누적합 생성
    // 패딩 주의
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psum[i][j] =
                psum[i-1][j] + psum[i][j-1]
                - psum[i-1][j-1] + arr[i-1][j-1];
        }
    }

    int maxSum = 0;

    // 모든 K×K 정사각형 검사
    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= n; j++) {
            int sum =
                psum[i+k][j+k]
                - psum[i][j+k]
                - psum[i+k][j]
                + psum[i][j];

            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;
    return 0;
}
