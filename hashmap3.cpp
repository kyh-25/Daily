/*
가장 많은 데이터
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string words[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // Please write your code here.
    int cnt = 0;
    unordered_map<string,int> map;
    for (int i = 0; i < n; i++) {
        if (map.find(words[i]) != map.end())
        {
            map[words[i]] += 1;
        }
        else{
            map[words[i]] = 1;
        }
    }
    
    for (auto it = map.begin(); it != map.end(); it++) {
        cnt = max(it->second, cnt); 
    }

    cout << cnt;
    return 0;
}
