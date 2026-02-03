//boj_11401_이항계수 - 나머지 연산, 페르마 소정리
/*
자연수 N과 정수 K가 주어졌을 때 이항 계수 nCk를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오
*/ 
#include<iostream>
using namespace std;

const long long mod = 1000000007L;

//빠른 제곱
long long mpow(long long x, long long y, long long mod) {
    long long result = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) result = (result * x) % mod;
        x = (x * x) % mod;
        y >>= 1; // y를 2로 나누기
    }
    return result;
}


int main(){
    int n,k; //입력
    long fact = 1; //분자
    long underC = 1; //분모1
    long underF = 1; //분모2
    long long under = 1; //분모

    cin >> n >> k;

    //분자 계산 n!
    for (size_t i = 1; i <= n; i++) fact = fact*i % mod;
    fact = fact%mod;

    //분모 계산
    for (size_t i = 1; i <= k; i++) underF = underF*i % mod; //분모1 K!
    for (size_t i = 1; i <= (n-k); i++)  underC = underC*i % mod; //분모2 (n-k)!
    under = underF*underC % mod;

    //페르마 소정리     
    fact = fact * mpow(under,mod-2,mod) % mod;

    cout << fact;
}