/*
동전 더하기
서로 다른 동전 N 종류로 금액 K 를 완성시키기 위해 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하세요.
*/

#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Please write your code here.
    int cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        cnt += k / coins[i];
        k %= coins[i];
    }

    cout << cnt;
    return 0;
}
