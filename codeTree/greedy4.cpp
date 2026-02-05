/*
수합치기
N개의 수가 주어졌을 때, 2개의 수를 골라 하나의 수로 합치는 과정을 단 하나의 수가 남을 때까지 반복하려고 합니다. 
이때 2개의 수가 a, b였다면, 이 두 수를 합치는 데 드는 비용은 a+b 입니다. 
N개의 수를 잘 합쳐 하나의 수가 되기까지의 가능한 최소 비용을 구하는 프로그램을 작성해보세요.
*/
#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];

priority_queue<int,vector<int>,greater<int>> minHeap;
    

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        minHeap.push(arr[i]);
    }

    // Please write your code here.
    int cnt = 0;
    while (minHeap.size() > 1){
        int min1 = minHeap.top(); minHeap.pop();
        int min2 = minHeap.top(); minHeap.pop();    
        minHeap.push(min1+min2);
        cnt += min1 + min2;
    }
    
    cout << cnt;
    return 0;
}
