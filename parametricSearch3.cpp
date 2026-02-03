/*
삼오무
1부터 차례대로 숫자를 적는데, 3이나 5의 배수는 숫자 대신 "Moo"라고 적습니다. 예를 들어 1부터 16까지의 숫자를 적는다면 아래와 같습니다.

1, 2, Moo, 4, Moo, Moo, 7, 8, Moo, Moo, 11, Moo, 13, 14, Moo, 16

이 때, N번째로 적히는 숫자는 무엇인지 구하는 프로그램을 작성해보세요.
*/

#include <iostream>
using namespace std;

long long n;

long long countNumbers(long long x) {
    long long moo = x / 3 + x / 5 - x / 15;
    return x - moo;
}

int main() {
    cin >> n;

    long long l = 1, r = 2 * n;  
    long long ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cnt = countNumbers(mid);

        if (cnt >= n) {
            ans = mid;      
            r = mid - 1;    
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}