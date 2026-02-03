/*
최대 점프 횟수
각 위치로부터의 최대 점프 가능 거리를 의미하는 N개의 수가 주어졌을 때, 
첫 번째 위치로부터 최대 몇 번 점프를 할 수 있는지를 구하는 프로그램을 작성해보세요. 
단, 동일한 위치로 점프하는 것은 불가능하고 앞으로 점프하는 것만 가능합니다.
*/

#include <iostream>

using namespace std;

int n;
int arr[1000];

int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1;
    }

    // Please write your code here.
    int maxJump = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if(dp[i] != -1){
            for(int k=1; k <= arr[i]; k++){
                if (k+i < n){
                    dp[k+i] = max(dp[k+i], dp[i] + 1);
                    maxJump = max(maxJump,dp[k+i]);
                }
            }
        }
    }

    cout << maxJump;

    return 0;
}
