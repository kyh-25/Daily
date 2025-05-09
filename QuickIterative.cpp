#include <iostream>
#include <stack>

/*
	2021111957 �迵��
	������ - ���ȯ����
	�ϳ��� ���ڸ� �������� ������ �������� ����
	������ ������ �������� ���� ������ �迭�� ���ÿ� �ְ�
	������ �������� �ݺ��ؼ� ������
*/

using namespace std;


void PrintArray(int* array, int right, int left) {
	//��¿�
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
	stack<int> nextPoint; //���� ���Ĺ迭
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
			int sortNum = curLeft; //���ؼ��� �ε���
			int sortVal = array[curLeft]; //���ؼ��� 

			while (curRight > curLeft)
			{
				while (array[--curRight] > sortVal); //������ �߰�
				while (array[++curLeft] < sortVal); //ū�� �߰�

				if (curRight > curLeft)
				{
					//swap
					int tmp = array[curRight];
					array[curRight] = array[curLeft];
					array[curLeft] = tmp;

					//��� ���
					PrintArray(array, right+1, left);
				}
			}

			//���ؼ��� �����迭 ���̷�
			array[sortNum] = array[curRight];
			array[curRight] = sortVal;

			//��� ���
			PrintArray(array, right + 1, left);
			cout << endl;

			nextPoint.push(curRight + 1); //ū�迭�� ����
			nextPoint.push(right); //ū �迭�� ������

			nextPoint.push(left); //�����迭�� ����
			nextPoint.push(curRight - 1); //�����迭�� ������
		}
	}
}


int main() {
	int array[10] = {};

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		array[i] = rand() % 100000 + 1;

	}

	cout << "����: ";
	PrintArray(array, 10, 0);
	cout << endl;
	

	QuickSortIt(array, sizeof(array) / sizeof(int) - 1, 0);


	cout << "���: ";
	PrintArray(array, 10, 0);
	cout << endl;
}
