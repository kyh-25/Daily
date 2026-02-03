/*
동전 거슬러주기
*/

#include <iostream>

using namespace std;

int N, M;
int coin[100];

int cnt[100001];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    // Please write your code here.
    for (int i = 0; i <= M; i++) {
        cnt[i] = -1;
    }
    cnt[0] = 0;

    for (int i = 0; i <= M; i++)
    {
        if (cnt[i] == -1) continue;  
        
        for (int j = 0; j < N; j++)
        {
            if ( (i+coin[j] <= M) && (cnt[i+coin[j]]==-1 || cnt[i] + 1 < cnt[i+coin[j]]))
            {
                cnt[i+coin[j]] = cnt[i] + 1;
            }
        }
    }
    

    if (cnt[M] == -1)
    {
        cout << -1;
        return 0;
    }
    
    cout << cnt[M];

    return 0;
}
