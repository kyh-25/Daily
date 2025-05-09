#include <iostream>

/*
	2021111957 �迵��
	������ - ��ȯ����
	�ϳ��� ���ڸ� �������� �迭�� ������ �������� ����
	���� ���� ���� ���� ���ڸ� �������� ū ���ڸ� ���������� ������
	���� �迭, ������ �迭�� ���� ����Լ��� ȣ���ؼ� �ݺ��Ѵ�
*/

using namespace std;


void PrintArray(int* array, int right, int left){
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

//�� ������
int Half(int* array, int right, int left) {
	int sortNum = left; //���ؼ��� �ε���
	int sortVal = array[left]; //���ؼ��� 

	//��¿�
	int printright = right;
	int printleft = left;

	while (right > left)
	{
		while (array[--right] > sortVal);//���� �� �߰�
		while (array[++left] < sortVal);//ū �� �߰�

		if (right > left)
		{
			//swap
			int tmp = array[right];
			array[right] = array[left];
			array[left] = tmp;

			//��� ���
			PrintArray(array,printright, printleft);
		}
		
	} 
	//���ؼ��� �����迭 ���̷�
	array[sortNum] = array[right];
	array[right] = sortVal;

	//��� ���
	PrintArray(array, printright, printleft);
	cout << endl;

	return right;
}


void QuickSortRe(int* array, int right, int left) {
	if (right > left)
	{
		int halfPoint = Half(array, right+1, left);
		QuickSortRe(array, halfPoint - 1, left); // �����迭
		QuickSortRe(array, right, halfPoint+1); // ū�迭
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
	

	QuickSortRe(array, sizeof(array) / sizeof(int) - 1, 0);


	cout << "���: ";
	PrintArray(array, 10, 0);
	cout << endl;
}
