#include <iostream>
#include <stack>

/*
	2021111957 김영훈
	퀵정렬 - 비순환구조
	하나의 숫자를 기준으로 반으로 나눠가며 정렬
	반으로 나누고 나누어진 왼쪽 오른쪽 배열을 스택에 넣고
	스택이 빌때까지 반복해서 나눈다
*/

using namespace std;


void PrintArray(int* array, int right, int left) {
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


void QuickSortIt(int* array, int right, int left) {
	stack<int> nextPoint; //다음 정렬배열
	nextPoint.push(left);
	nextPoint.push(right);
	
	
	while (!nextPoint.empty())
	{
		right = nextPoint.top();
		nextPoint.pop();
		left = nextPoint.top();
		nextPoint.pop();

		int curRight = right + 1;
		int curLeft = left;

		if (right > left)
		{
			int sortNum = curLeft; //기준숫자 인덱스
			int sortVal = array[curLeft]; //기준숫자 

			while (curRight > curLeft)
			{
				while (array[--curRight] > sortVal); //작은수 발견
				while (array[++curLeft] < sortVal); //큰수 발견

				if (curRight > curLeft)
				{
					//swap
					int tmp = array[curRight];
					array[curRight] = array[curLeft];
					array[curLeft] = tmp;

					//결과 출력
					PrintArray(array, right+1, left);
				}
			}

			//기준숫자 나눈배열 사이로
			array[sortNum] = array[curRight];
			array[curRight] = sortVal;

			//결과 출력
			PrintArray(array, right + 1, left);
			cout << endl;

			nextPoint.push(curRight + 1); //큰배열의 왼쪽
			nextPoint.push(right); //큰 배열의 오른쪽

			nextPoint.push(left); //작은배열의 왼쪽
			nextPoint.push(curRight - 1); //작은배열의 오른쪽
		}
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
	

	QuickSortIt(array, sizeof(array) / sizeof(int) - 1, 0);


	cout << "결과: ";
	PrintArray(array, 10, 0);
	cout << endl;
}
