//백준1655. 가운데를 말해요
/*
백준이는 동생에게 "가운데를 말해요"라는 게임을 가르쳐주었다.
이 게임은 백준이가 수를 하나씩 말하면, 동생이 그 수까지의 수들 중에서
가운데에 있는 수를 말하는 게임이다. 
예를 들어, 백준이가 1, 5, 2, 10, -99, 7까지 수를 말했으면,
동생은 1, 1, 2, 2, 2,2, 5까지 수를 말해야 한다.
(짝수번째 수까지 말했을 때는 가운데에 있는 두 수 중 작은 수를 말해야 한다.)
*/

#include<iostream>
using namespace std;

// arr와 order를 합병정렬로 함께 정렬
void merge(int* arr, int* order, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];
    int* L_order = new int[n1];
    int* R_order = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        L_order[i] = order[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
        R_order[i] = order[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            order[k] = L_order[i];
            i++;
        } else {
            arr[k] = R[j];
            order[k] = R_order[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        order[k] = L_order[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        order[k] = R_order[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
    delete[] L_order;
    delete[] R_order;
}

void mergeSort(int* arr, int* order, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, order, left, mid);
        mergeSort(arr, order, mid + 1, right);
        merge(arr, order, left, mid, right);
    }
}

int main(){
    int n; // n: 수의 개수

    cin >> n;
    int* arr = new int[n]; // 수를 저장할 배열
    int* order = new int[n]; // 정렬된 수의 원래 순서

    // 입력 받기
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        order[i] = i;
    }
    
    // 합병정렬로 arr와 order를 함께 정렬
    mergeSort(arr, order, 0, n - 1);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << arr[order[i]];
    }
    cout << endl;

    delete[] arr;
    delete[] order;
    return 0;
}