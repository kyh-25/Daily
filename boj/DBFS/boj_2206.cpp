/*
벽 부수고 이동하기
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
*/
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int maze[1001][1001];
int dist[1001][1001][2];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Node{
    int x,y,wall;
};

int main(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
            maze[i][j]=s[j]-'0';
    }

    queue<Node> q;

    q.push({0,0,0});
    dist[0][0][0]=1;

    while(!q.empty()){

        auto cur=q.front(); q.pop();

        int x=cur.x;
        int y=cur.y;
        int wall=cur.wall;

        if(x==n-1 && y==m-1){
            cout<<dist[x][y][wall];
            return 0;
        }

        for(int i=0;i<4;i++){

            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;

            // 길
            if(maze[nx][ny]==0 && dist[nx][ny][wall]==0){
                dist[nx][ny][wall]=dist[x][y][wall]+1;
                q.push({nx,ny,wall});
            }

            // 벽인데 아직 안 부쉈다면
            if(maze[nx][ny]==1 && wall==0){
                dist[nx][ny][1]=dist[x][y][0]+1;
                q.push({nx,ny,1});
            }
        }
    }

    cout<<-1;
}