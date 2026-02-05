/*
데이터 비교
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Please write your code here.
    unordered_set<int> a1;
    for (int i = 0; i < n; i++) {
        a1.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++) {
        if (a1.find(arr2[i]) != a1.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}
