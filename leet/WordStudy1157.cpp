#include <iostream>
using namespace std;

char ToBig(char c){
    if ('Z'<c)
    {
        c -= 32;
    }
    return c;
}

int main() {
    string word;
    int count[26] = {0};
    char maxIndex = -2;
    int maxVale = 0;

    cin >> word;

    //카운트
    for (int i = 0; i < word.length(); i++)
    {
        char cur = word.at(i);
        cur = ToBig(cur);
        count[cur-65]++;
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (maxVale == count[i]) //중복
        {
            maxIndex = -2;
        }
        else if (maxVale < count[i])
        {
            maxIndex = i;
            maxVale = count[i];
        }
    }
    maxIndex += 65;

    cout << maxIndex;
    return 0;
}
