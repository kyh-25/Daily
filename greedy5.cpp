/*
회의실 준비 구현
하나의 회의실이 있고, N개의 회의 요청이 들어왔습니다. 각 회의의 시작 시간과 끝 시간이 주어져 있으며, 
한 회의가 시작되면 도중에 그만둘 수 없고, 한 회의가 끝나는 직후에 동시에 다른 회의가 시작될 수 있습니다. 
적절하게 회의 요청을 수락하여 최대로 많은 회의가 진행되도록 하는 프로그램을 작성하세요.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int s[100000];
int e[100000];

bool cmp(int a, int b) {
    if(e[a] == e[b])
        return s[a] < s[b];
    return e[a] < e[b];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }

    // Please write your code here.
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), cmp);

    int cnt = 1;
    int previEnd= e[idx[0]];
    for(int i=1; i<n; i++){
        if(s[idx[i]] >= previEnd){
            cnt++;
            previEnd = e[idx[i]];
        }
            
    }

    cout << cnt;

    return 0;
}
