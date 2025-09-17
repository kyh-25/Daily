// BOJ_3197_백조의호수 - BFS, 시뮬레이션
/*
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.

호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.

호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.

아래에는 세 가지 예가 있다.

...XXXXXX..XX.XXX ....XXXX.......XX .....XX.......... 
....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... 
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... 
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX.... 
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... 
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ 
..XXXXX...XXX.... ....XX.....X..... ................. 
....XXXXX.XXX.... .....XX....X..... ................. 
      처음               첫째 날             둘째 날
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.

며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1500;
int R, C;
char lake[MAX][MAX];
int visited[MAX][MAX];

pair<int,int> swans[2];
queue<pair<int,int>> swanQ, swanNQ, waterQ, waterNQ;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool moveSwan() {
    while(!swanQ.empty()) {
        auto [x,y] = swanQ.front(); swanQ.pop();
        for(int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx<0 || ny<0 || nx>=R || ny>=C) continue; //예외처리
            if(visited[nx][ny]) continue; // 이미 방문한 곳
            visited[nx][ny] = 1;

            if(lake[nx][ny] == 'L') {
                if(make_pair(nx,ny) == swans[1]) return true; // 두 번째 백조 발견
                swanQ.push({nx,ny}); //같은 백조
            } else if(lake[nx][ny] == '.') {
                swanQ.push({nx,ny});
            } else { // 얼음
                swanNQ.push({nx,ny});
            }
        }
    }
    return false;
}

void meltIce() {
    while(!waterQ.empty()) {
        auto [x,y] = waterQ.front(); waterQ.pop();
        for(int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx<0 || ny<0 || nx>=R || ny>=C) continue; //예외처리
            if(lake[nx][ny] == 'X') { // 얼음
                lake[nx][ny] = '.';
                waterNQ.push({nx,ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); //속도 향상
    cin.tie(0);

    //입력
    cin >> R >> C;
    int swanCnt = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> lake[i][j];
            if(lake[i][j] != 'X') waterQ.push({i,j});
            if(lake[i][j] == 'L') swans[swanCnt++] = {i,j};
        }
    }

    swanQ.push(swans[0]);
    visited[swans[0].first][swans[0].second] = 1;

    int days = 0;
    while(true) {
        if(moveSwan()) break;   // 백조끼리 만남
        meltIce();              // 얼음 녹이기
        swap(swanQ, swanNQ);
        swap(waterQ, waterNQ);
        while(!swanNQ.empty()) swanNQ.pop();
        while(!waterNQ.empty()) waterNQ.pop();
        days++;
    }

    cout << days << "\n";
    return 0;
}
