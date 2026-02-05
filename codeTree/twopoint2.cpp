/*
겹치는 숫자가 없는 최대 구간
N개의 숫자가 주어졌을 때, 구간 내에 중복되는 숫자가 전혀 없는 경우 중 가능한 최대 구간의 크기를 구하는 프로그램을 작성해보세요.
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    unordered_map<int,int> m;
    int low = 0;
    int maxLen = -1;

    for (int i = 0; i < n; i++) {
        //중복
        if(m.find(arr[i]) != m.end()){
            low = max(low, m[arr[i]] + 1);   
        }
        m[arr[i]] = i;
        maxLen = max(i-low+1, maxLen);
    }

    cout << maxLen;

    return 0;
}
