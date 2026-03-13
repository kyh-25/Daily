/*
랜선 자르기
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 
그리고 필요한 랜선의 개수 N이 입력된다. 
K는 1이상 10,000이하의 정수이고, 
N은 1이상 1,000,000이하의 정수이다. 
그리고 항상 K ≦ N 이다. 
그 후 K줄에 걸쳐 
이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 
랜선의 길이는 231-1보다 작거나 같은 자연수이다.

첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.
*/

#include<iostream>
#include<algorithm>

using namespace std;

int lan[1000000];

long long cal(int n,int target){
    long long sum =0;
    for(int i=0; i<n; i++){
        sum += lan[i]/target;            
    }
    return sum;
}

int binarySearch(int n, int max,int x){
    long long l = 1;
    long long r = max;
    int ans = 0;

    while(l <= r){
        int mid = (l + r) / 2;
        long long cnt = cal(n,mid);

        if(cnt >= x){
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int maxlen = 0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> lan[i];
        maxlen = max(maxlen,lan[i]);
    }

    cout << binarySearch(n,maxlen,m);
}
