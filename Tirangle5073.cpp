#include <iostream>
using namespace std;

// 백준 5073번
// 어떤 삼각형인지 판단

int main() {
    int a,b,c;

    while (1)
    {
        cin >> a >> b >> c;

        if (a+b+c == 0)//끝
        {
            break;
        }
        
        if (max(max(a,b),c)*2 >= a+b+c) //삼각아님
        {
            cout << "Invalid " << endl;
        }
        else if (a==b && a==c) //정삼각형
        {
            cout << "Equilateral" << endl;
        }
        else if (a==b || a==c || b==c) //이등변
        {
            cout << "Isosceles " << endl;
        }
        else //다 다름
        {
            cout << "Scalene" << endl;
        }
    }
    
    
    return 0;
}
