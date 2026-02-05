/*
점 개수 세기 3
수직선 상의 서로 다른 위치에 N개의 점에 주어졌을 때, Q개의 질의에 대해 각각 구간 내 점의 개수를 출력하는 프로그램을 작성해보세요.
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;
int n, q;
int points[MAX_N];
int a[MAX_N], b[MAX_N];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    unordered_map<int,int> m;
    sort(points, points+n);

    for(int i=1; i<=n; i++){
        m.insert({points[i-1],i});
    }

    for (int i = 0; i < q; i++) {
        cout << m[b[i]]-m[a[i]] + 1 << endl;
    }

    return 0;
}
