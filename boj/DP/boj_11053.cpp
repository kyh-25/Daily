/*
LIS - 최장 부분 수열
dp[i]가 길이가 i인 증가하는 부분 수열 중 끝점의 최솟값을 의미하고 현재 탐색 중인 원소를 here이라고 할 때,

dp 배열이 비어 있거나 dp의 마지막 원소보다 here이 더 클 경우, dp 배열의 뒤에 here을 추가
그렇지 않을 경우, dp 배열에서 here의 lower_bound를 찾아 그 자리를 here로 바꾼다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n+1);
    vector<int> dp;
    arr[0] = 0;

    for (int i = 1; i < n+1; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < n+1; ++i) {
        // 비어있거나 dp의 마지막 원소보다 here이 크다면 dp에 here을 추가
        if (dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        } else { // 그렇지 않다면 lower_bound를 찾아 dp 배열 갱신
            int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[lb] = arr[i];
        }
    }

    cout << dp.size() << "\n";    

    return 0;
}