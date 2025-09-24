//백준 2748 피보나치 수열

#include <iostream>
using namespace std;
long long fibo[100] = {0,1};
int main() {
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[n] << '\n';
    return 0;
}