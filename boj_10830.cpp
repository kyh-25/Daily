#include<iostream>
using namespace std;

#define MAXN 5
const int mod = 1000;

//행렬곱
void cross(int res[MAXN][MAXN], int b[MAXN][MAXN],int n){
    int tmp[MAXN][MAXN] = {0};

    for (int i = 0; i < n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++){
                tmp[i][j] = (tmp[i][j] + res[i][k] * b[k][j]) % mod;
            }
        }
    }

    //복사
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = tmp[i][j];

}

//빠른 제곱
void mpow(int arr[MAXN][MAXN], long long b, int n) {
    int res[MAXN][MAXN];   // 결과 행렬 (단위 행렬)
    int base[MAXN][MAXN];  // 밑이 되는 행렬

    // res = 단위 행렬로 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = (i == j);

    // base = arr 복사
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            base[i][j] = arr[i][j];

    // 분할 정복 거듭제곱
    while (b > 0) {
        if (b & 1) cross(res, base, n);   // res = res * base
        cross(base, base, n);             // base = base * base
        b >>= 1;
    }

    // 최종 결과 res -> arr 복사
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = res[i][j];
}

int main(){
    int n;
    long long b;
    int arr[MAXN][MAXN];
    
    //입력
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }    
    }
    
    //빠른거듭제곱
    mpow(arr,b,n);

    //출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }    
        cout << endl;
    }
    
    return 0;
}