#include <iostream>

/*
	2021111957	김영훈
	버블정렬 - 비순환구조
	인접하는 두 요소를 비교하여 더 큰 수를 뒤로 보낸다
	가장 큰수를 가장 뒤로 보내기를 반복하여 정렬한다
*/

using namespace std;

void BubbleSortIn(int* array, int length) {
	int tmp;
	bool swapped;
	
	for (int i = 0; i < length - 1; i++)
	{
		swapped = false;

		for (int j=0; j< length-1 - i; j++)
		{
			if (array[j] > array[j+1]) //앞에 수가 더 크다
			{
				//swap
				tmp = array[j];
				array[j] = array[j+1];
				array[j + 1] = tmp;
				swapped = true;
			}
			
			//단계별 출력용
			cout << i + 1 << "번째 루프: ";
			for (int k = 0; k < length; k++)
			{
				cout << array[k] << " ";
			}
			cout << endl;
		}

		if (swapped == false) // 정렬완료 - 한번도 교환이 없다
		{
			break;
		}

		cout << endl;
	}
}


int main() {
	int array[8] = { 30,20,40,10,5,10,30,15 };

	BubbleSortIn(array, sizeof(array) / sizeof(int));

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}


