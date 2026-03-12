/*
수 찾기
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
*/

#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;

int a[100000];
unordered_set<int> map;

int isThereMAP(int tmp){
    if(map.find(tmp) != map.end()){
        return 1;
    }    
    return 0;
}

int binarySearch(int n, int x){
    int l = 0;
    int r = n - 1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(a[mid] == x) return 1;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    return 0;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        map.insert(a[i]);
    } 

    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        cout << isThereMAP(tmp) << '\n';
    }
}