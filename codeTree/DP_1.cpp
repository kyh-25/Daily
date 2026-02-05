/*
계단 오르기
N층 높이의 계단을 오르려고 합니다. 한 번에 정확히 2계단 혹은 3계단 단위로만 올라갈 수 있다고 했을 때, 
N층 높이의 계단에 올라가기 위한 서로 다른 방법의 수를 구하는 프로그램을 작성해보세요. 
단, 항상 2계단 혹은 3계단 단위로만 올라갈 수 있기에 N층까지 정확히 1계단이 남은 상황에서는 N층으로 올라갈 수 있는 방법이 전혀 없음에 유의합니다.

*/
#include <iostream>

using namespace std;

int n;
int dp[1001];
int jump[2] = {2,3};

int modN = 10007;

int main() {
    cin >> n;

    // Please write your code here.
    dp[0] = 1;
    for(int i=0; i<=n; i++){
        dp[i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<2; j++){
            if(i-jump[j] >= 0){
                dp[i] += dp[i-jump[j]] % modN;
            }
        }
    }

    cout << dp[n] % modN;
    return 0;
}