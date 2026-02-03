/*
가장 짧은 부분합
원소가 N개 들어 있는 수열에서 특정 구간을 잡았을 때 그 합이 S 이상이 되는 것 중, 
가장 짧은 구간의 길이를 구하는 프로그램을 작성해보세요.
*/
#include <iostream>
#include<algorithm>

using namespace std;

int n, s;
int arr[100000];

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int sum = 0;
    int low = 0;

    int minLen = n+1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum >= s){
            while(sum-arr[low] >= s && low < i){
                sum -= arr[low];
                low++;
            }
            minLen = min(minLen, i - low + 1);
        }
    }

    if (minLen != n+1)
        cout << minLen;
    else
        cout << "-1";

    return 0;
}
