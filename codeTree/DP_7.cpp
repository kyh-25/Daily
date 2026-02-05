/*
막대기 나누기

길이가 N인 막대기가 하나 주어졌을 때, 막대기를 잘 쪼개어 최대 수익을 얻고자 합니다. 
1부터 N까지 각각의 길이에 대해 팔았을 때 얻을 수 있는 수익 정보가 주어졌을 때, 
최대 수익을 얻는 프로그램을 작성해보세요.
*/
#include <iostream>

using namespace std;

int n;
int profit[100];

int dp[101];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    // Please write your code here.

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i+j < n){
                dp[i+j] = max(dp[i+j], dp[i] + profit[j]);
            }
        }
    }

    return 0;
}
