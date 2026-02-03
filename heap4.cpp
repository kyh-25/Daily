/*
가장 가까운 점
*/

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    priority_queue<tuple<long long, int, int>,
    vector<tuple<long long, int, int>>,
    greater<tuple<long long, int, int>>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(make_tuple(x[i]+y[i],x[i],y[i]));    
    }
    
    for(int i = 0; i < m; i++) {        
        tuple<long long, int, int> best_thing = pq.top(); // x * y, x, y 순으로 가장 우선순위 높은 경우를 찾아줍니다.
        pq.pop();

        int px, py;
        tie(ignore, px, py) = best_thing;  // 우리가 원하는 x, y 값만 tuple로부터 가져와줍니다.
        px += 2;
        py += 2;
        pq.push(make_tuple(px+py,px,py));
    }
    
    tuple<long long, int, int> best_thing = pq.top();
    int px, py;
    tie(ignore, px, py) = best_thing;
    cout << px << " " << py;
    
    return 0;
}
