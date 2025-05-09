#include <iostream>

/*
	2021111957 김영훈
	퀵정렬 - 순환구조
	하나의 숫자를 기준으로 배열을 반으로 나눠가며 정렬
	기준 숫자 보다 작은 숫자를 왼쪽으로 큰 숫자를 오른쪽으로 모으고
	왼쪽 배열, 오른쪽 배열을 각각 재귀함수로 호출해서 반복한다
*/

using namespace std;


void PrintArray(int* array, int right, int left){
	//출력용
	for (int k = 0; k < left; k++)
	{
		cout.width(7);
		cout << "";
	}
	for (int k = left; k < right; k++)
	{
		cout.width(7);
		cout << array[k];
	}
	cout << endl;
}

//반 나누기
int Half(int* array, int right, int left) {
	int sortNum = left; //기준숫자 인덱스
	int sortVal = array[left]; //기준숫자 

	//출력용
	int printright = right;
	int printleft = left;

	while (right > left)
	{
		while (array[--right] > sortVal);//작은 수 발견
		while (array[++left] < sortVal);//큰 수 발견

		if (right > left)
		{
			//swap
			int tmp = array[right];
			array[right] = array[left];
			array[left] = tmp;

			//결과 출력
			PrintArray(array,printright, printleft);
		}
		
	} 
	//기준숫자 나눈배열 사이로
	array[sortNum] = array[right];
	array[right] = sortVal;

	//결과 출력
	PrintArray(array, printright, printleft);
	cout << endl;

	return right;
}


void QuickSortRe(int* array, int right, int left) {
	if (right > left)
	{
		int halfPoint = Half(array, right+1, left);
		QuickSortRe(array, halfPoint - 1, left); // 작은배열
		QuickSortRe(array, right, halfPoint+1); // 큰배열
	}
}



int main() {
	int array[10] = {};

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		array[i] = rand() % 100000 + 1;

	}

	cout << "원본: ";
	PrintArray(array, 10, 0);
	cout << endl;
	

	QuickSortRe(array, sizeof(array) / sizeof(int) - 1, 0);


	cout << "결과: ";
	PrintArray(array, 10, 0);
	cout << endl;
}
