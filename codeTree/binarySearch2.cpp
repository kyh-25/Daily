/*
수의 개수
N개의 수가 오름차순으로 정렬된 상태로 주어집니다. 
이후 M개의 수가 추가적으로 주어졌을 때, 
각각의 수가 처음 주어진 N개의 수 중 몇 번 나왔는지를 구하는 프로그램을 작성해보세요.
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int arr[100000];
int query[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }

    // Please write your code here.
    for (int i = 0; i < m; i++) {
        int x = query[i];

        int l = lower_bound(arr, arr + n, x) - arr;
        int r = upper_bound(arr, arr + n, x) - arr;

        cout << (r - l) << '\n';
    }


    return 0;
}
