//boj 2933 미네랄 - BFS, 시뮬레이션
/*
창영과 상근은 한 동굴을 놓고 소유권을 주장하고 있다. 두 사람은 막대기를 서로에게 던지는 방법을 이용해 누구의 소유인지를 결정하기로 했다. 
싸움은 동굴에서 벌어진다. 동굴에는 미네랄이 저장되어 있으며, 던진 막대기가 미네랄을 파괴할 수도 있다.
동굴은 R행 C열로 나타낼 수 있으며, R×C칸으로 이루어져 있다. 각 칸은 비어있거나 미네랄을 포함하고 있으며, 네 방향 중 하나로 인접한 미네랄이 포함된 두 칸은 같은 클러스터이다.
창영은 동굴의 왼쪽에 서있고, 상근은 오른쪽에 서있다. 
두 사람은 턴을 번갈아가며 막대기를 던진다. 막대를 던지기 전에 던질 높이를 정해야 한다. 막대는 땅과 수평을 이루며 날아간다.
막대가 날아가다가 미네랄을 만나면, 그 칸에 있는 미네랄은 모두 파괴되고 막대는 그 자리에서 이동을 멈춘다.
미네랄이 파괴된 이후에 남은 클러스터가 분리될 수도 있다. 
새롭게 생성된 클러스터가 떠 있는 경우에는 중력에 의해서 바닥으로 떨어지게 된다. 떨어지는 동안 클러스터의 모양은 변하지 않는다. 
클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다. 클러스터는 다른 클러스터 위에 떨어질 수 있고, 그 이후에는 합쳐지게 된다.
동굴에 있는 미네랄의 모양과 두 사람이 던진 막대의 높이가 주어진다. 
모든 막대를 던지고 난 이후에 미네랄 모양을 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <queue>
using namespace std;

const int maxR = 100;
const int maxC = 100;
int r,c;

char cave[maxR][maxC];
bool visited[maxR][maxC];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//한 클러스트에서 각열마다 최저 높이
int* getDist(int x,int y){
    int* minH = new int[maxC];
    queue<pair<int,int>> next;
    next.push({x,y});

    for(int i=0; i<maxC; i++)
        minH[i] = maxC;

    while (!next.empty())
    {
        auto [x,y] = next.front(); next.pop();
        for(int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue; //예외처리
            if(visited[nx][ny]) continue; // 이미 방문한 곳
            visited[nx][ny] = 1;

            //클러스터다
            if (cave[nx][ny] == 'X')
            {
                next.push({nx,ny});
                minH[nx] = min(ny,minH[nx]);
            }
        }
    }
    
} 

int main(){

    return 0;
}