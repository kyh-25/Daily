//백준1655. 가운데를 말해요 - 힙
/*
백준이는 동생에게 "가운데를 말해요"라는 게임을 가르쳐주었다.
이 게임은 백준이가 수를 하나씩 말하면, 동생이 그 수까지의 수들 중에서
가운데에 있는 수를 말하는 게임이다. 
예를 들어, 백준이가 1, 5, 2, 10, -99, 7까지 수를 말했으면,
동생은 1, 1, 2, 2, 2,2, 5까지 수를 말해야 한다.
(짝수번째 수까지 말했을 때는 가운데에 있는 두 수 중 작은 수를 말해야 한다.)
*/

#include <iostream>
using namespace std;

// const int MAXN = 100001;

// // 최대힙
// class MaxHeap {
//     int heap[MAXN];
//     int sz;
// public:
//     MaxHeap() : sz(0) {}
//     void push(int val) {
//         heap[sz] = val;
//         int idx = sz++;
//         while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
//             swap(heap[(idx - 1) / 2], heap[idx]);
//             idx = (idx - 1) / 2;
//         }
//     }
//     void pop() {
//         heap[0] = heap[--sz];
//         int idx = 0;
//         while (true) {
//             int left = idx * 2 + 1, right = idx * 2 + 2, largest = idx;
//             if (left < sz && heap[left] > heap[largest]) largest = left;
//             if (right < sz && heap[right] > heap[largest]) largest = right;
//             if (largest == idx) break;
//             swap(heap[idx], heap[largest]);
//             idx = largest;
//         }
//     }
//     int top() const { return heap[0]; }
//     int size() const { return sz; }
//     bool empty() const { return sz == 0; }
// };

// // 최소힙
// class MinHeap {
//     int heap[MAXN];
//     int sz;
// public:
//     MinHeap() : sz(0) {}
//     void push(int val) {
//         heap[sz] = val;
//         int idx = sz++;
//         while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
//             swap(heap[(idx - 1) / 2], heap[idx]);
//             idx = (idx - 1) / 2;
//         }
//     }
//     void pop() {
//         heap[0] = heap[--sz];
//         int idx = 0;
//         while (true) {
//             int left = idx * 2 + 1, right = idx * 2 + 2, smallest = idx;
//             if (left < sz && heap[left] < heap[smallest]) smallest = left;
//             if (right < sz && heap[right] < heap[smallest]) smallest = right;
//             if (smallest == idx) break;
//             swap(heap[idx], heap[smallest]);
//             idx = smallest;
//         }
//     }
//     int top() const { return heap[0]; }
//     int size() const { return sz; }
//     bool empty() const { return sz == 0; }
// };

#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> maxHeap; // 중앙값 이하
    priority_queue<int, vector<int>, greater<int>> minHeap; // 중앙값 이상

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        // maxHeap이 비었거나 num이 중앙값 이하이면 maxHeap에 삽입
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // 힙 크기 조절
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 중앙값 출력 (maxHeap.top())
        cout << maxHeap.top() << '\n';
    }

    return 0;
}
