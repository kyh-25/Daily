
#include <iostream>

/*
	2021111957	�迵��
	�������� - ��ȯ����
	�����ϴ� �� ��Ҹ� ���Ͽ� �� ū ���� �η� ������
	�� �ε������� ���ϰ� ���� �ε����� �������� ����Լ��� ȣ���Ѵ�
	������ �ѹ��� ��ȯ�� �̷������ ������ ��ģ��
*/

using namespace std;


void BubbleSortRe(int* array, int length, int i, bool swapped) {
	if (i >= length-1) // ���� ����
	{
		if (swapped == true)//not sorted
		{
			i = 0; 
			cout << endl;
			BubbleSortRe(array, length, i, false); // ó������
		}
	}
	else
	{
		if (array[i] > array[i + 1]) //ū���� �ڷ�
		{
			//swap
			int tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			swapped = true;
		}

		//��¿�
		for (int k = 0; k < length; k++)
		{
			cout << array[k] << " ";
		}
		cout << endl;

		BubbleSortRe(array, length, i + 1, swapped);//���� ����
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
