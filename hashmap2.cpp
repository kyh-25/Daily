/*
수 등장 횟수 
*/

#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
int nums[MAX_N];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++) {
        if (map.find(arr[i]) != map.end())
        {
            map[arr[i]] += 1;
        }
        else{
            map[arr[i]] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (map.find(nums[i]) != map.end())
        {
            cout << map.find(nums[i])->second << " ";
        }
        else{
            cout << "0 ";
        }
    }

    return 0;
}
