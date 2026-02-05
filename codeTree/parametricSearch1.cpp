/*
자연수 n개의 합
1부터 N까지의 자연수의 합이 S 이하인 경우 중 가능한 N의 최댓값을 구하는 프로그램을 작성하세요
*/
#include <iostream>
using namespace std;

long long S;

bool can(long long n) {
    return n * (n + 1) / 2 <= S;
}

int main() {
    cin >> S;

    long long lo = 0, hi =  2000000000LL;
    long long ans = 0;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) {
            ans = mid;        // 가능한 N
            lo = mid + 1;     // 더 큰 N 탐색
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}