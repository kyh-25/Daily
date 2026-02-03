#include <iostream>
using namespace std;

int main() {
    int num;
    int count = 1;
    int six = 1;

    cin >> num;

    while (num > six)
    {
        six += count*6;
        count++;
    }
    
    cout << count;

    return 0;
}
