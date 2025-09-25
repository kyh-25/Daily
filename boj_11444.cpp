//boj 111444 피보나치6 - 피보나치 수열 (행렬), 행렬의 빠른 거듭제곱
/*
입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.
출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.
*/
//https://www.acmicpc.net/blog/view/28

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;

//행렬 곱
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    long long n;

    cin >> n; //n번째 피보나치 수

    if (n <= 1) {
        cout << n << '\n';
        return 0;
    }

    matrix ans = {{1, 0}, {0, 1}}; //단위 행렬
    matrix a = {{1, 1}, {1, 0}}; //베이스

    //빠른 거듭 제곱
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1] << '\n'; //fn 출력

    return 0;
}