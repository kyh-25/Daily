/*
동전 0
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 
이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오
*/

#include<iostream>

using namespace std;

int a[1000000];

int main(){
    int n, k;

    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        cnt += k / a[i];
        k = k % a[i];
    }
    cout << cnt;
}