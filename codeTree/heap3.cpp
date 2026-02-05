/*
    최소 정수 출력
*/

#include <iostream>
#include <queue>

using namespace std;

int n;
int x[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Please write your code here.
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0)
        {
            if (q.empty())
                cout << "0 "<< endl;
            else{
                cout << -q.top() << endl;
                q.pop();
            }
        }
        else
            q.push(-x[i]);
    }


    return 0;
}
