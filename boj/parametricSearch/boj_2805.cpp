/*
나무 자르기
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
*/

#include<iostream>
#include<algorithm>

using namespace std;

int tree[1000000];

long long cal(int n,int target){
    long long sum =0;
    for(int i=0; i<n; i++){
        if(tree[i] > target)
            sum += tree[i]-target;
    }
    return sum;
}

int binarySearch(int n, int max,int x){
    int l = 0;
    int r = max;
    int ans = 0;

    while(l <= r){
        int mid = (l + r) / 2;
        long long len = cal(n,mid);

        if(len >= x){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    return ans;
}


int main(){
    int n,m;
    int maxlen = 0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tree[i];
        maxlen = max(maxlen,tree[i]);
    }

    cout << binarySearch(n,maxlen,m);
}