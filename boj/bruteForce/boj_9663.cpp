/*
N-Queen
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

=>
✔️ 1) 한 행에 하나의 퀸만 둔다
각 행마다 하나씩 배치하면 행 충돌은 자동 해결
✔️ 2) 열과 대각선만 검사하면 됨
열: 같은 column인지 확인
대각선:
↘ 방향: row + col 값이 같으면 충돌
↗ 방향: row - col 값이 같으면 충돌
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int result = 0;
vector<int> col; // col[i] = i행에 놓인 퀸의 열 위치

bool isValid(int row) {
    for (int i = 0; i < row; i++) {
        if (col[row] == col[i] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true;
}

void dfs(int row) {
    if (row == N) {
        result++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[row] = i;
        if (isValid(row)) {
            dfs(row + 1);
        }
    }
}

int main() {
    cin >> N;
    col.resize(N);
    dfs(0);
    cout << result << endl;
}