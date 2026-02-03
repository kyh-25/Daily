
#include <iostream>

/*
	2021111957	김영훈
	버블정렬 - 순환구조
	인접하는 두 요소를 비교하여 더 큰 수를 두로 보낸다
	현 인덱스에서 비교하고 다음 인덱스를 기준으로 재귀함수를 호출한다
	끝까지 한번도 교환이 이루어지지 않으면 마친다
*/

using namespace std;


void BubbleSortRe(int* array, int length, int i, bool swapped) {
	if (i >= length-1) // 끝에 도달
	{
		if (swapped == true)//not sorted
		{
			i = 0; 
			cout << endl;
			BubbleSortRe(array, length, i, false); // 처음으로
		}
	}
	else
	{
		if (array[i] > array[i + 1]) //큰수를 뒤로
		{
			//swap
			int tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			swapped = true;
		}

		//출력용
		for (int k = 0; k < length; k++)
		{
			cout << array[k] << " ";
		}
		cout << endl;

		BubbleSortRe(array, length, i + 1, swapped);//다음 순번
	}
}


int main() {
	int array[8] = { 30,20,40,10,5,10,30,15 };

	BubbleSortRe(array, sizeof(array) / sizeof(int),0,false);

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
