/*
정수 N개의 합2
N개의 원소로 이루어진 수열이 주어졌을 때, 이 중 연속하는 K개의 원소들의 합 중 가장 큰 값을 구하는 프로그램을 작성하세요
근데 슬라이딩 방식으로 풀음
*/
#include <iostream>

using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int sum = 0;
    int maxSum = 0;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    maxSum = sum;
    for(int i=k; i<n; i++){
        sum -= arr[i-k];
        sum += arr[i];
        maxSum = max(sum,maxSum);
    }

    cout << maxSum;

    return 0;
}
