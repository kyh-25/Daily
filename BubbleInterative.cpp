#include <iostream>

/*
	2021111957	�迵��
	�������� - ���ȯ����
	�����ϴ� �� ��Ҹ� ���Ͽ� �� ū ���� �ڷ� ������
	���� ū���� ���� �ڷ� �����⸦ �ݺ��Ͽ� �����Ѵ�
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
			if (array[j] > array[j+1]) //�տ� ���� �� ũ��
			{
				//swap
				tmp = array[j];
				array[j] = array[j+1];
				array[j + 1] = tmp;
				swapped = true;
			}
			
			//�ܰ躰 ��¿�
			cout << i + 1 << "��° ����: ";
			for (int k = 0; k < length; k++)
			{
				cout << array[k] << " ";
			}
			cout << endl;
		}

		if (swapped == false) // ���ĿϷ� - �ѹ��� ��ȯ�� ����
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


