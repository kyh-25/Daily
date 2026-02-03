//boj 2749 피보나치 수열 - 피사노 주기
//첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다
//M = 10^k 일 때, k > 2 라면, 주기는 항상 15 × 10^(k-1) 

#include <iostream>
using namespace std;
const int mod = 1000000;
const int p = mod/10*15;
int fibo[p] = {0,1};
int main() {
    long long n;
    cin >> n;
    for (int i=2; i<p; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod;
    }
    cout << fibo[n%p] << '\n';
    return 0;
}