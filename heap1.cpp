/*
힙 = 부모가 자식보다 항상 크거나 작은 이진 트리
배열/연결 리스트로 구현

c++의 우선순위 힙 STL은 힙으로 구현되어 있음
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;

int main() {
    cin >> N;

    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(command == "pop"){
            cout << q.top() << endl;
            q.pop();
        }
        else if(command == "size"){
            cout << q.size() << endl;
        }
        else if(command == "empty"){
            cout << q.empty() << endl;
        }
        else if(command == "top"){
            cout << q.top() << endl;
        }
    }
    return 0;
}
