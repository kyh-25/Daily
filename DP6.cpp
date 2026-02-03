/*
연속 부분 합의 최댓값 구하기
*/

#include <iostream>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x = arr[0];
    int current = x;   // i에서 끝나는 최대 합
    int answer = x;    // 전체 최대값

    for (int i = 1; i < n; i++) {
        x = arr[i];
        current = max(x, current + x);
        answer = max(answer, current);
    }

    cout << answer;
    return 0;
}
