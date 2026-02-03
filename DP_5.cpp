/*
최대 동전 거슬러 주기
N개의 동전의 종류가 주어졌을 때, 금액 M을 거슬러주기 위한 방법 중 가능한 최대 동전의 수를 구해주는 프로그램을 작성해보세요. 단, 같은 종류의 동전을 여러 번 사용하여 거슬러 줄 수 있습니다.

예를 들어 N=3, M=10, 동전의 종류는 3, 4, 5 일때

10=5+5 이렇게 거슬러주면 총 2개의 동전이 사용되지만

10=3+3+4 이렇게 거슬러 주면 총 3개의 동전으로 돈을 거슬러 줄 수 있습니다.
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
            if ( (i+coin[j] <= M) && (cnt[i+coin[j]]==-1 || cnt[i] + 1 > cnt[i+coin[j]]))
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
