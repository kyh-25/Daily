/*
숫자 빠르게 찾기
N개의 숫자가 오름차순으로 정렬된 상태로 주어집니다. 
이후 M개의 숫자가 추가적으로 주어졌을 때, 
각각의 숫자가 처음 주어진 N개의 숫자 중 몇 번째로 나온 숫자인지를 구하는 프로그램을 작성해보세요.
*/

#include <iostream>
#include <algorithm>

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
        int target = query[i];
        auto it = lower_bound(arr,arr+n,query[i]);
        if (it != arr+n && *it == query[i])
            cout << it-arr + 1 << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}
