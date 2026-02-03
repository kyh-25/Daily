/*
쪼개어 배낭 채우기
도둑이 보석방을 털러 갔습니다. 보석방에는 N개의 보석이 있고, 
도둑 가방의 크기는 M이기 때문에 이보다 더 많은 양의 무게에 해당하는 보석들을 담아 나올 수는 없습니다. 
또한, 보석은 종류별로 단 하나씩만 있으며 각 보석을 원하는 만큼 쪼개어 담는 것이 가능합니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int w[100000];
int v[100000];


bool cmp(int a, int b) {
    return (long long)v[a] * w[b] > (long long)v[b] * w[a];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    // Please write your code here.
    vector<int> idx(N);
    for (int i = 0; i < N; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), cmp);


    int currentW = 0;
    double value = 0.0;
    for (int i = 0; i < N; i++) {
        int id = idx[i];

        if (currentW >= M)
            break;

        // 전부 담을 수 있는 경우
        if (currentW + w[id] <= M) {
            currentW += w[id];
            value += v[id];
        }
        // 일부만 담는 경우
        else {
            int remain = M - currentW;
            value += (double)v[id] * remain / w[id];
            break;
        }
    }
    
    printf("%.3f",value);
    return 0;
}
