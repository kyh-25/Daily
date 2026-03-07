/*
컨베이어 벨트를 이용해 로봇들을 건너편으로 옮기려고 한다. 로봇을 옮기는 과정에서는 아래와 같은 일이 순서대로 일어난다.

벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
종료되었을 때 몇 번째 단계가 진행 중이었는지 구해보자. 가장 처음 수행되는 단계는 1번째 단계이다.
*/
#include <iostream>
using namespace std;

int dura[200];
int belt[200];

int main(){
    int n, k;
    int cnt = 0;
    int broke = 0;
    int start = 0;

    cin >> n >> k;
    for(int i = 0; i < 2*n; i++)
        cin >> dura[i];
    
    while(true){
        cnt++;

        // 1. 벨트 회전 (start만 이동)
        start = (start - 1 + 2*n) % (2*n);
        if(belt[(start + n-1) % (2*n)] == 1) belt[(start + n-1) % (2*n)] = 0; 
        
        // 2. 로봇 이동 (뒤에서부터)
        for(int i = n-2; i >= 0; i--){
            int cur  = (start + i) % (2*n);
            int next = (start + i + 1) % (2*n);

            if(belt[cur] == 1 && belt[next] == 0 && dura[next] > 0){
                belt[cur] = 0;
                if(i + 1 != n - 1) belt[next] = 1;  // N번 칸이면 내리기
                dura[next]--;
                if(dura[next] == 0) broke++;
            }
        }

        // 3. 로봇 추가
        if(dura[start] > 0 && belt[start] == 0){
            belt[start] = 1;
            dura[start]--;
            if(dura[start] == 0) broke++;
        }

        // 4. 종료 체크
        if(broke >= k) break;
    }
    
    cout << cnt;
}