/*
집합의 표현
두집합의 합집합, 교집합 연산
집합을 표현하는 프로그램을 작성하시오
첫째 줄에 
n,m이 주어진다. 
m은 입력으로 주어지는 연산의 개수이다. 
다음 m개의 줄에는 각각의 연산이 주어진다. 
합집합은 0 a b의 형태로 입력이 주어진다. 
이는 a가 포함되어 있는 집합과, 
b가 포함되어 있는 집합을 합친다는 의미이다. 
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 
1 a b의 형태로 입력이 주어진다. 
이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

//root 찾기
int find(int x) {
    if (parent[x] == x)
        return x;
    //x가 자식 노드일 경우, 부모 노드에 대해 재귀실행한다.
    //***이 때, parent[x]를 최종적으로 찾을 root 노드로 갱신한다.***
    return parent[x] = find(parent[x]); // path compression
}

//b의 루트의 부모를 a루트로 설정
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0) {
            unite(a, b);
        } 
        else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}