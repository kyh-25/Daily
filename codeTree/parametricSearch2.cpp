/*
정수 분배하기
N개의 정수를 분배하여 같은 크기의 정수 K를 M개 만들려고 할 때, 
만들 수 있는 K값의 최댓값을 구하는 프로그램을 작성해보세요. 
이때, M개를 만들어야 한다는 의미는 M개 이상을 얻어내면 된다는 뜻임에 유의합니다.

단, N개의 정수를 분배할 때는 제한 없이 정수를 분배해도 괜찮지만, 각
 정수에서 분배하고 남은 정수들을 합쳐서 새로운 정수로 만들 수는 없습니다.
*/

#include <iostream>

using namespace std;

int n, m;
int arr[10000];
int l = 1, r = 0;

int count(int k) {
    int cnt = 0;
    for(int i =0; i<n; i++){
        cnt += arr[i] / k;
    }
    
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r = max(r,arr[i]);
    }

    // Please write your code here.
    int ans = 0;
    
    while(l<=r){
        int mid = (l+r) / 2;
        int cnt = count(mid);

        if (cnt >= m){
            ans = mid;
            l = mid + 1;
        }
        else if(cnt < m){
            r = mid - 1;
        }   
    }
    cout << ans;
    return 0;
}
