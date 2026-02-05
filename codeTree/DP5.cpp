/*
부분 수열의 합이 M
*/

#include <iostream>

using namespace std;

int n, m;
int A[100];

int cnt[10000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    for (int i = 0; i <= m; i++) {
        cnt[i] = -1;
    }
    cnt[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (cnt[j] != -1 && j+A[i] <= m)
            {
                if (cnt[j+ A[i]] == -1 || 
                    cnt[j+ A[i]] > cnt[j] + 1)
                {
                    cnt[j+A[i]] = cnt[j] + 1;
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        cout << cnt[i];
    }
    cout << cnt[m];

    return 0;
}
