#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
        }
    }

    // Please write your code here.
    unordered_map<int,int> s;
    for (int i = 0; i < n; i++) {
        if(cmd[i] == "add"){
            s[k[i]] = v[i];
        }
        else if(cmd[i] == "remove"){
            s.erase(k[i]);
        }
        else if(cmd[i] == "find"){
            if (s.find(k[i]) != s.end()){
                cout << s.find(k[i])->second << endl;
            }
            else{
                cout << "None" << endl;
            }
        }
        else {
            
        }
    }
    return 0;
}
