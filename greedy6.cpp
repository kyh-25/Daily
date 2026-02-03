/*
최대수 만들기
N개의 수가 주어졌을 때, 
적당한 순서에 맞춰 나열하여 각 수들을 붙여 만들 수 있는 수 중 가능한 최댓값을 출력하는 프로그램을 작성해보세요.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[50000];

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    cin >> n;

    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    sort(nums.begin(), nums.end(), cmp);

    // 모두 0인 경우 처리
    if (nums[0] == "0") {
        cout << 0;
        return 0;
    }

    // 이어 붙이기
    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }

    return 0;
}
