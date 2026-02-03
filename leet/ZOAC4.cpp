#include <iostream>
using namespace std;

int main() {
    int height,width,n,m;
    int curH=0, curW=0;
    int count=0;
    cin >> height >> width >> n >> m;
    //cout << height << width << n << m << endl;

    // height = 5; width = 4; n = 1; m = 1;
    // int** classRoom = new int*[height];
    // for (size_t i = 0; i < height; i++){
    //     classRoom[i] = new int[width];
    // }

    // for (size_t i = 0; i < height; i++)
    // {
    //     for (size_t j = 0; j < width; j++)
    //     {
    //         classRoom[i][j] = 0;       
    //     }
    // }

    do
    {
        curW = 0;
        do
        {
            //classRoom[curH][curW] = 1;
            count++;
            curW += m+1;
        } while (width>curW);

        curH += n+1;
    } while (height>curH);
    cout << count;

    
    // for (size_t i = 0; i < height; i++)
    // {
    //     for (size_t j = 0; j  < width; j++)
    //     {
    //         cout << classRoom[i][j] << " ";        
    //     }
    //     cout << endl;
    // }
    
}
